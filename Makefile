# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalena <msalena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 21:52:41 by msalena           #+#    #+#              #
#    Updated: 2021/09/03 21:52:41 by msalena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SR1			= server.c

SR2			= client.c

OJ1			= ${SR1:.c=.o}

OJ2			= ${SR2:.c=.o}

HD1			= server.h

HD2			= libft/libft.h

GCC			= gcc -Wall -Wextra -Werror

N1			= server

N2			= client

LIBFT		= libft/

LIBFT.a		= ${LIBFT}libft.a

all:		lib ${N1} ${N2}

%.o:		%.c ${LIBFT.a} ${HD1} ${HD2}
			${GCC} -c -o $@ $<

$(N1): 		${OJ1}
			${GCC} ${OJ1} ${LIBFT.a} -o ${N1}

$(N2): 		${OJ2}
			${GCC} ${OJ2} ${LIBFT.a} -o ${N2}

lib:
			@cd ${LIBFT} && ${MAKE}

re:			fclean all

clean:
			rm -f ${OJ1} ${OJ2}
			cd ${LIBFT} && ${MAKE} clean

fclean:		clean
			rm -f ${N1} ${N2}
			cd ${LIBFT} && ${MAKE} fclean

.PHONY:		all re clean fclean
