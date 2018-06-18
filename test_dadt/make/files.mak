# Adjust the following if necessary

######################################## CODE ROOT PATH ###########################################
CODE_ROOT:=$(PWD)/..

######################################## HEADER FILE PATH #########################################
HEADER_PATH:=$(CODE_ROOT)/../dbase/header
HEADER_PATH+=$(CODE_ROOT)/../dadt/header
HEADER_PATH+=$(CODE_ROOT)/../dtest/header
HEADER_PATH+=$(CODE_ROOT)/header

######################################## SOURCE FILE PATH #########################################
SOURCE_PATH:=$(CODE_ROOT)/source

######################################## TARGET INFO ##############################################
TARGET:=test_dadt

# set build_type "DEBUG" to get a debug version, or anything else to get a release version
BUILD_TYPE:=DEBUG

#INSTALL_PATH:=/home/dercury/bin
INSTALL_PATH:=

######################################## MACROS & LIBS ############################################
# macros used when compiling
MACROS:=OS_LINUX

# libs used when linking, must be in REVERSE order
LIBS:=$(CODE_ROOT)/../dtest/make/output/lib/libdtest.so \
      $(CODE_ROOT)/../dadt/make/output/lib/libdadt.so \
      $(CODE_ROOT)/../dbase/make/output/lib/libdbase.so

######################################## THE END ##################################################

