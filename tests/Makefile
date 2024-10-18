# =========================================================================
#   Unity - A Test Framework for C
#   ThrowTheSwitch.org
#   Copyright (c) 2007-24 Mike Karlesky, Mark VanderVoord, & Greg Williams
#   SPDX-License-Identifier: MIT
# =========================================================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=../unity
PROJ_SRC = ../project/srcs
GNL = ../project/libs/get_next_line/

LIBFT_PATH	= ../project/libs/libft
LIBFT_NAME	= libft.a
LIBS = -L$(LIBFT_PATH) -lft

UTILS = $(PROJ_SRC)/utils/print_error.c \
	    $(PROJ_SRC)/utils/ft_isspace.c \
	    $(PROJ_SRC)/utils/safe_malloc.c \
	    $(PROJ_SRC)/utils/check_color.c \
	    $(PROJ_SRC)/utils/ft_addline.c \
		$(PROJ_SRC)/utils/ft_straddchar.c \
    	$(GNL)get_next_line.c \
    	$(GNL)get_next_line_utils.c


PARSER_SRC = $(PROJ_SRC)/parser/meta_init.c \
   			 $(PROJ_SRC)/parser/parser.c \
   			 $(PROJ_SRC)/parser/parse_dir.c \
   			 $(PROJ_SRC)/parser/parse_map.c \
   			 $(PROJ_SRC)/parser/check_map.c 

# CFLAGS=-std=c89
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

TARGET_BASE1=test_parser
# TARGET_BASE2=test2
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
# TARGET2 = $(TARGET_BASE2)$(TARGET_EXTENSION)
PARSER_TEST_SRC=$(UNITY_ROOT)/src/unity.c $(PARSER_SRC) $(UTILS) test_parser.c  parser_test_runner.c
# SRC_FILES2=$(UNITY_ROOT)/src/unity.c src/ProductionCode2.c test/TestProductionCode2.c test/test_runners/TestProductionCode2_Runner.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src
SYMBOLS=

all: clean default

default: ${LIBFT_PATH}/${LIBFT_NAME} $(PARSER_TEST_SRC) #$(SRC_FILES2)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(PARSER_TEST_SRC) $(LIBS) -o $(TARGET1)
	- ./$(TARGET1)

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

# $(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES2) -o $(TARGET2)
# - ./$(TARGET2)

# test/test_runners/TestProductionCode_Runner.c: test/TestProductionCode.c
# 	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/TestProductionCode.c  test/test_runners/TestProductionCode_Runner.c
# test/test_runners/TestProductionCode2_Runner.c: test/TestProductionCode2.c
# 	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/TestProductionCode2.c test/test_runners/TestProductionCode2_Runner.c

clean:
	make fclean -C $(LIBFT_PATH)
	$(CLEANUP) $(TARGET1) $(TARGET2)

ci: CFLAGS += -Werror
ci: default