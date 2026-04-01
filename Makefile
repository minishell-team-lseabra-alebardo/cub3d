# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 17:29:52 by lseabra-          #+#    #+#              #
#    Updated: 2026/03/31 15:12:32 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
RESET	= \033[0m

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

#Names
NAME		= cub3d
PROJ_NAME	= CUB3D

#Paths
BUILD_PATH		= build
INC_PATH		= include
SRC_PATH		= src
PARSING_PATH	= $(SRC_PATH)/parsing

# Source files

PARSING_SRC = $(addprefix $(PARSING_PATH)/, \
	ft_get_next_line.c \
	ft_init_surface.c \
	ft_init_texture.c \
	ft_parse_map.c \
	ft_parse_rgb.c \
	ft_parse.c \
	ft_put_error.c \
	ft_validate_arg.c \
	ft_validate_map_boundaries.c \
	ft_validate_map_content.c \
	str_utils.c \
)

SRC	= $(PARSING_SRC) $(addprefix $(SRC_PATH)/, \
		main.c \
)

# Object files
OBJ	= $(addprefix $(BUILD_PATH)/, $(notdir $(SRC:.c=.o)))

#Compiler and Flags
CC		= cc
C_FLAGS	= -Wall -Wextra -Werror -g
INC		= -I$(INC_PATH)
ASAN	= -fsanitize=address

#Utility Commands
MKDIR	= mkdir -p
RM		= rm -f
RMDIR	= rm -rf
ECHO	= echo

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(C_FLAGS) $(ASAN) $(INC) $(OBJ) -o $@
	@$(ECHO) "$(GREEN)[$(PROJ_NAME)]:$(RESET) executable compiled: $(NAME)"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(C_FLAGS) $(INC) -c $< -o $@

$(BUILD_PATH)/%.o: $(PARSING_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(C_FLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR) $(BUILD_PATH)
	@$(ECHO) "$(GREEN)[$(PROJ_NAME)]:$(RESET) directory created: $(BUILD_PATH)"

clean:
	@$(RMDIR) $(BUILD_PATH)
	@$(ECHO) "$(RED)[$(PROJ_NAME)]:$(RESET) directory removed: $(BUILD_PATH)"

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "$(RED)[$(PROJ_NAME)]:$(RESET) executable removed: $(NAME)"

re: fclean all