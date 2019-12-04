# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tjans <tjans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/25 18:31:12 by tjans         #+#    #+#                  #
#    Updated: 2019/11/30 16:43:35 by tjans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_DIR	:= src conversions formatters
INC_DIR	:= inc
OBJ_DIR := obj

TARGET	:= libftprintf.a
LIBFT	:= libft
VPATH	:= $(SRC_DIR)

CFLAGS	:=	-g -c -Wall -Wextra -I $(INC_DIR) -I $(LIBFT)/out

S_PRINTF	:= printf.c parse_flag.c formatter.c ctable.c nconv.c
S_CONV		:= p_sign.c p_str.c p_int.c p_char.c p_uint.c p_ptr.c p_hex.c
S_FMT		:= prefix_str.c pad_str.c strupper.c

SRCS	:= $(S_PRINTF) $(S_CONV) $(S_FMT)
HDRS	:= printf.h conversions.h formatters.h
OBJS	:= $(SRCS:.c=.o)

$(OBJ_DIR)/%.o : %.c $(addprefix $(INC_DIR)/,$(HDRS)) | dirs
	@echo CC $<
	@$(CC) $(CFLAGS) -o $@ $<

all: $(LIBFT)/out/libft.a $(TARGET)

$(LIBFT)/out/libft.a:
	$(MAKE) -C $(LIBFT)

$(TARGET): $(addprefix $(OBJ_DIR)/,$(OBJS))
	@echo Linking $(TARGET)
	@$(AR) rcs $@ $^
	@echo ---DONE---

clean:
	@echo Removed intermediates
	@$(RM) $(addprefix $(OBJ_DIR)/,$(OBJS))

fclean: clean
	@echo Removed output
	@$(RM) $(TARGET)

re: fclean all

ftclean: fclean
	@$(MAKE) -C $(LIBFT) fclean

re_all: fclean ftclean all

dirs:
	@echo Compiling $(TARGET)...
	@echo Host: $$(uname -rms)
	@echo CFLAGS: $(CFLAGS)
	@echo ---Start---
	@mkdir -p $(OBJ_DIR)

.PHONY: libft dirs
