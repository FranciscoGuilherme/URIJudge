include environment.mk

#---------------------------------------------------
# HIDING THE GCC COMPILATION
#---------------------------------------------------

MAKEFLAGS += --quiet

#---------------------------------------------------
# CONFIGURING DEPENDENCES
#---------------------------------------------------

CPPUTEST_INCLUDES  := -pthread -I/usr/include/CppUTest/* -I/usr/include/CppUTestExt/*
CPPUTEST_LIBRARIES := $(shell pkg-config --libs cpputest)

#---------------------------------------------------
# GNUCC PARAMETERS
#---------------------------------------------------

CFLAGS   := -Wall -g $(CPPUTEST_INCLUDES)
LDFLAGS  := $(CPPUTEST_LIBRARIES)

#---------------------------------------------------
# OTHER PARAMETERS
#---------------------------------------------------

BINARY   := $(BINARY_DIR)/1001
TEST_BIN := $(BINARY_DIR)/tests

#---------------------------------------------------
# SOURCE FILES (*.c, *.o)
#---------------------------------------------------

SOURCES := $(wildcard $(SOURCE_DIR)/**/*.c $(SOURCE_DIR)/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

#---------------------------------------------------
# TESTS FILES (*.c, *.o)
#---------------------------------------------------

TESTS_METHODS := $(filter-out ../src/main.c, $(SOURCES))
TESTS_SOURCES := $(wildcard $(TESTS_DIR)/**/*.cpp $(TESTS_DIR)/*.cpp $(TESTS_METHODS))
TESTS_OBJECTS := $(patsubst %.cpp, %.o, $(TESTS_SOURCES))
