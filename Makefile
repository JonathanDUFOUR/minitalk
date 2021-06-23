# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 22:30:33 by jodufour          #+#    #+#              #
#    Updated: 2021/06/23 11:39:25 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC			=	gcc -c -o
LINKER		=	gcc -o
MAKEDIR		=	mkdir -p
RM			=	rm -rf

######################################
#             EXECUTABLE             #
######################################
CLT			=	client
SRV			=	server

#######################################
#             DIRECTORIES             #
#######################################
SRCD		=	srcs/
OBJD		=	objs/
INCLUDE		=	includes/

CMN_SRCD	=	${SRCD}
CMN_OBJD	=	${OBJD}

CLT_SRCD	=	clt/
CLT_SRCD	:=	${addprefix ${SRCD}, ${CLT_SRCD}}
CLT_OBJD	=	${CLT_SRCD}
CLT_OBJD	:=	${addprefix ${OBJD}, ${CLT_OBJD}}

SRV_SRCD	=	srv/
SRV_SRCD	:=	${addprefix ${SRCD}, ${SRV_SRCD}}
SRV_OBJD	=	${SRV_SRCD}
SRV_OBJD	:=	${addprefix ${OBJD}, ${SRV_OBJD}}

######################################
#            SOURCE FILES            #
######################################
CMN_SRCS	=	\
				mt_putbyte.c

SRV_SRCS	=	\
				main.c			\
				mt_get_ctx.c	\
				mt_listen.c

CLT_SRCS	=	\
				main.c			\
				mt_atopid.c		\
				mt_isdigit.c	\
				mt_isspace.c

######################################
#            OBJECT FILES            #
######################################
CMN_OBJS	=	${CMN_SRCS:.c=.o}
CMN_OBJS	:=	${addprefix ${CMN_OBJD}, ${CMN_OBJS}}

SRV_OBJS	=	${SRV_SRCS:.c=.o}
SRV_OBJS	:=	${addprefix ${SRV_OBJD}, ${SRV_OBJS}}

CLT_OBJS	=	${CLT_SRCS:.c=.o}
CLT_OBJS	:=	${addprefix ${CLT_OBJD}, ${CLT_OBJS}}

CMN_DEPS	=	${CMN_OBJS:.o=.d}
SRV_DEPS	=	${SRV_OBJS:.o=.d}
CLT_DEPS	=	${CLT_OBJS:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS		=	-Wall -Wextra -MMD -I${INCLUDE}
LDFLAGS		=	

ifeq (DEBUG, true)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################

all:	${SRV} ${CLT}

${SRV}:	${SRV_OBJS} ${CMN_OBJS}
	${LINKER} $@ ${LDFLAGS} $^

${CLT}:	${CLT_OBJS} ${CMN_OBJS}
	${LINKER} $@ ${LDFLAGS} $^

-include ${CMN_DEPS}

${CMN_OBJD}%.o:	${CMN_SRCD}%.c
	@${MAKEDIR} ${OBJD}
	@${MAKEDIR} ${CMN_OBJD}
	${CC} $@ ${CFLAGS} $<

-include ${SRV_DEPS}

${SRV_OBJD}%.o:	${SRV_SRCD}%.c
	@${MAKEDIR} ${OBJD}
	@${MAKEDIR} ${SRV_OBJD}
	${CC} $@ ${CFLAGS} $<

-include ${CLT_DEPS}

${CLT_OBJD}%.o:	${CLT_SRCD}%.c
	@${MAKEDIR} ${OBJD}
	@${MAKEDIR} ${CLT_OBJD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${CLT} ${SRV}

re:	fclean all

.PHONY:	all clean fclean re
