# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tjans <tjans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/25 18:31:12 by tjans         #+#    #+#                  #
#    Updated: 2019/12/18 16:12:07 by tjans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_DIR	:= src conversions formatters utils
INC_DIR	:= inc
OBJ_DIR := obj

NAME	:= libftprintf.a
VPATH	:= $(SRC_DIR)

CFLAGS	:= -c -Wall -Wextra -Werror -I $(INC_DIR)

S_PRINTF	:= printf.c parse_flag.c ctable.c nconv.c printer.c
S_CONV		:= p_sign.c p_str.c p_int.c p_char.c p_uint.c p_ptr.c p_hex.c
S_FMT		:= prefix_str.c pad_str.c strupper.c field_width.c
S_UTILS		:= $(addprefix utils_, bzero.c calloc.c ft_str_is.c \
				memcpy.c memset.c strdup.c strjoin.c strlcat.c  \
				strlcpy.c strlen.c)

SRCS	:= $(S_PRINTF) $(S_CONV) $(S_FMT) $(S_UTILS)
HDRS	:= printf.h conversions.h formatters.h utils.h
OBJS	:= $(SRCS:.c=.o)

$(OBJ_DIR)/%.o : %.c $(addprefix $(INC_DIR)/,$(HDRS)) | dirs
	@echo CC $<
	@$(CC) $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR)/,$(OBJS))
	@echo Linking $(NAME)
	@$(AR) rcs $@ $^
	@echo ---DONE---

clean:
	@echo Removed intermediates
	@$(RM) $(addprefix $(OBJ_DIR)/,$(OBJS))
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo Removed output
	@$(RM) $(NAME)

re: fclean all

ftclean: fclean
	@$(MAKE) -C $(LIBFT) fclean

re_all: fclean ftclean all

dirs:
	@echo Compiling $(NAME)...
	@echo Host: $$(uname -rms)
	@echo CFLAGS: $(CFLAGS)
	@echo ---Start---
	@mkdir -p $(OBJ_DIR)

.PHONY: dirs
