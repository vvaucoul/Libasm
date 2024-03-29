# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 18:00:15 by vvaucoul          #+#    #+#              #
#    Updated: 2022/10/28 17:02:43 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### NAMES (outputs)
NAME		=	libasm.a
NAMEC		=	test_libasm
NAMECB		=	test_libasm_bonus

### DIR ###

DS	=	srcs/
DSB	=	srcs_bonus/

### SOURCES ###
SRCS		= 		$(DS)ft_strlen.s	\
					$(DS)ft_strcpy.s	\
					$(DS)ft_read.s		\
					$(DS)ft_write.s		\
					$(DS)ft_strcmp.s	\
					$(DS)ft_strdup.s

SRCB		=		$(DSB)ft_atoi_base_bonus.s			\
					$(DSB)ft_list_push_front_bonus.s	\
					$(DSB)ft_list_remove_if_bonus.s		\
					$(DSB)ft_list_size_bonus.s			\
					$(DSB)ft_list_sort_bonus.s

SRCC =				main.c
SRCCB =				main_bonus.c

###	INCLUDE FOR .C ###
INCLUDE	=	-I./include

### COMPILATION ###
ASM = 		nasm
CC	=		gcc
AR = 		ar -rc

### FLAGS ###
FLAGS = 	-f macho64

### OBJS ###
OBJ =		$(SRCS:.s=.o)
OBJB =		$(SRCB:.s=.o)

%.o: %.s
		@$(ASM) $(FLAGS) $< -o $@

### RULES ###

all:	$(NAME)

$(NAME):     $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@printf "$(GREEN)	--->|LIBASM.a created|<----$(NOC)\n"

bonus:	$(OBJ) $(OBJB)
	@$(AR) $(NAME) $(OBJ) $(OBJB)
	@printf "$(GREEN)	--->|LIBASM.a created with bonus|<----$(NOC)\n"

test:	all
	@$(CC) $(SRCC) -L. -lasm $(INCLUDE) -o $(NAMEC)
	@printf "$(GREEN)	--->|test_libasm created|<----$(NOC)\n"

test_bonus:	bonus
	@$(CC) $(SRCCB) -L. -lasm $(INCLUDE) -o $(NAMECB)
	@printf "$(GREEN)	--->|test_libasm created with bonus|<----$(NOC)\n"

clean:
	@printf "$(YELLOW)	--->|Clean files|<----$(NOC)\n"
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@printf "$(YELLOW)	--->|Remove libasm.a|<----$(NOC)\n"
	@rm -f $(NAME) $(BONUS) $(NAMEC) $(NAMECB)

re: fclean all

.PHONY:     all clean re fclean
