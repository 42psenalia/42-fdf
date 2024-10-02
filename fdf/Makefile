# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 14:29:26 by psenalia          #+#    #+#              #
#    Updated: 2024/09/23 14:31:24 by psenalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------
#			Directories
#------------------------------------------------------------------------------

SRC		= pushswap.c ft_atol.c mkrawset.c formstack.c checker.c idealset.c \
		  presetting.c swaptop.c pushtop.c rotator.c ctrotor.c \
		  logic_quartile.c logic_percentile.c logic_efficiency.c \
		  logic_efficiency5.c logic_pushback.c freerror.c main.c

OBJ		= $(SRC:.c=.o)

#------------------------------------------------------------------------------
#			Variables
#------------------------------------------------------------------------------

NAME		= push_swap
LIBPS		= push_swap.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -rf

#------------------------------------------------------------------------------
#			Targets
#------------------------------------------------------------------------------

all:		$(NAME)

$(NAME):	$(LIBPS)
			$(CC) $< -o $@

$(LIBPS):	$(OBJ)
			ar rcs $(LIBPS) $(OBJ)

%.o : %.c	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ) $(LIBPS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
