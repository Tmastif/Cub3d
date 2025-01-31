# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 18:32:21 by ilazar            #+#    #+#              #
#    Updated: 2025/01/31 16:37:07 by ilazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = main.c map.c errors.c init.c elements.c get_next_line_bonus.c gnl.c gnl_utils.c \
		parse_utils.c

# Object files
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Output executable
TARGET = map

# Static library
LIBNAME = ftplus
LIBGNL = gnl
LIBFILE = libftplus.a

# Include and library paths
INCLUDES = -I cub3d_parse.h -I gnl.h -I get_next_line_bonus.h
LIBPATH = -L .

# Default target
all: $(TARGET)

# Linking the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBPATH) -l$(LIBNAME) -l$(LIBGNL)

# Compiling source files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean