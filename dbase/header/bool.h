/******************************************************************************/
/**
 * @file          bool.h
 * @brief         bool type
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _BOOL_H
#define _BOOL_H

/***************************** include files **********************************/

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef enum tagBool
{
    FALSE = 0,
    TRUE,
} Bool;

/******************************************************************************/
/**
 * @func          char* bool_to_str(Bool value)
 * @brief         bool_to_str
 * @param[in]     Bool value: a boolean value
 * @return        char*: "TRUE" or "FALSE"
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern char* bool_to_str(const Bool value);

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // _BOOL_H

