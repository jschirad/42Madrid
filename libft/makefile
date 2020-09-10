# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 16:41:58 by jschirad          #+#    #+#              #
#    Updated: 2019/11/17 15:32:53 by jschirad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c ft_memcmp.c ft_memmove.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlcpy.c \
	   ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalpha.c ft_atoi.c ft_strncmp.c \
	   ft_isdigit.c ft_isalnum.c ft_strlen.c ft_memchr.c ft_strchr.c ft_strrchr.c  ft_strdup.c \
	   ft_strlcat.c ft_strnstr.c ft_calloc.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strtrim.c ft_split.c ft_strmapi.c \
	   ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c  \
	   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	   ft_lstmap_bonus.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) libft.h
		gcc -Wall -Werror -Wextra -c $(SRCS)
		ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)
fclean: clean
		rm -f  $(NAME)
re:		fclean all

.PHONY: all, clean, fclean, re
