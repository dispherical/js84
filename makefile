# ----------------------------
# Makefile Options
# ----------------------------

NAME = JS84
DESCRIPTION = "Packaged JavaScript file with engine"
COMPRESSED = NO
HAS_PRINTF = YES

CFLAGS = -Wall -Wextra -Oz -DJS_DUMP -lm -std=c99 -otest -DUK_USE_DEBUG -D_MSC_VER -D_MSC_VER=1800
CXXFLAGS = -Wall -Wextra -Oz -DJS_DUMP -lm -std=c99 -otest -DUK_USE_DEBUG -D_MSC_VER

# ----------------------------
include $(shell cedev-config --makefile)