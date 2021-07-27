# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/23 16:41:54 by rgilles           #+#    #+#              #
#    Updated: 2020/03/23 16:41:56 by rgilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCSF	= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c		\
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c	\
			ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c		\
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_sqrt.c ft_strchr.c ft_strdup.c	\
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
			ft_putchar.c ft_putendl.c ft_putnbr.c ft_putstr.c ft_lstnew.c \
			ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c\
			ft_lstiter.c ft_lstclear.c ft_lstmap.c ft_putnbr_unsigned_fd.c \
			ft_putnbr_uns.c ft_nbdigits_base.c ft_putnbr_uns_base_fd.c \
			ft_putnbr_uns_base.c get_next_line.c ft_isspace.c ft_realloc.c \
			ft_error.c ft_split_free.c
SRCDIR	=	srcs/
INDIR	=	includes/
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	$(addprefix $(SRCDIR),$(SRCSF))
OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${CFLAGS} -I${INDIR} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar -vcrs ${NAME} ${OBJS}

clean:
			rm -f ${SRCDIR}*.o

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		clean fclean re
