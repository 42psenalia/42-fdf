# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psenalia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 13:43:33 by psenalia          #+#    #+#              #
#    Updated: 2024/03/18 13:39:41 by psenalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------
#			Directories
#------------------------------------------------------------------------------

SRC		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_toupper.c ft_tolower.c ft_strncmp.c ft_atoi.c \
		  ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_memset.c \
		  ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_memcpy.c ft_memmove.c \
		  ft_bzero.c ft_calloc.c ft_strdup.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		  ft_substr.c ft_strtrim.c ft_strjoin.c ft_itoa.c ft_split.c \
		  ft_striteri.c ft_strmapi.c

OBJ		= $(SRC:.c=.o)

#------------------------------------------------------------------------------
#			Variables
#------------------------------------------------------------------------------

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

#------------------------------------------------------------------------------
#			Targets
#------------------------------------------------------------------------------

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)
clean:
			$(RM) -r $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
