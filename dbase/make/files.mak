# Adjust the following if necessary

######################################## CODE ROOT PATH ###########################################
CODE_ROOT:=$(PWD)/..

######################################## HEADER FILE PATH #########################################
HEADER_PATH:=$(CODE_ROOT)/header

######################################## SOURCE FILE PATH #########################################
SOURCE_PATH:=$(CODE_ROOT)/source

######################################## TARGET INFO ##############################################
TARGET:=libdbase.so

# set build_type "DEBUG" to get a debug version, or anything else to get a release version
BUILD_TYPE:=DEBUG

#INSTALL_PATH:=/home/dercury/bin
INSTALL_PATH:=

######################################## MACROS & LIBS ############################################
# macros used when compiling
MACROS:=OS_LINUX

# libs used when linking
LIBS:=

###################################################################################################

