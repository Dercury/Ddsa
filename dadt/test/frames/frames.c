#include <stdlib.h>

#include "list.h"
#include "frames.h"

int alloc_frame(List *frames)
{
    int frame_number, *data;

    if (0 == frames->size)
    {
        /* Return that there are no frames available. */
        return -1;
    }
    else
    {
        if (0 != list_remove_next(frames, NULL, (void **)&data))
        {
            /* Return that a frame could not be retrieved. */
            return -1;
        }
        else
        {
            /* Store the number of the available frame. */
            frame_number = *data;
            free(data);
        }
    }

    return frame_number;
}

int free_frame(List *frames, int frame_number)
{
    int *data;

    /* Allocate storage for the frame number */
    if (NULL == (data = (int *)malloc(sizeof(int))))
    {
        return -1;
    }

    /* Put the frame back in the list of available frames */
    *data = frame_number;
    if (0 != list_insert_next(frames, NULL, data))
    {
        return -1;
    }

    return 0;
}

