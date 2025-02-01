# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inbar <inbar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 18:32:21 by ilazar            #+#    #+#              #
#    Updated: 2025/02/01 17:22:32 by inbar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = main.c parser.c errors.c init.c elements.c get_next_line_bonus.c gnl.c gnl_utils.c \
		utils_parse.c debug_parse.c

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
INCLUDES = -I ./folder_name
LIBPATH = -L .

# Default target
all: $(TARGET)

# Linking the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBPATH) -l$(LIBNAME) -l$(LIBGNL)

# Compiling source files
#put includes in a folder:
# $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean