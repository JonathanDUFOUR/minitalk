# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 22:30:33 by jodufour          #+#    #+#              #
#    Updated: 2021/11/08 10:29:42 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC			=	clang -c -o
LINKER		=	clang -o
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

SRV_SRCD	:=	server/
SRV_OBJD	:=	${SRV_SRCD}
SRV_SRCD	:=	${addprefix ${SRCD}, ${SRV_SRCD}}
SRV_OBJD	:=	${addprefix ${OBJD}, ${SRV_OBJD}}

CLT_SRCD	:=	client/
CLT_OBJD	:=	${CLT_SRCD}
CLT_SRCD	:=	${addprefix ${SRCD}, ${CLT_SRCD}}
CLT_OBJD	:=	${addprefix ${OBJD}, ${CLT_OBJD}}

CMN_SRCD	:=	common/
CMN_OBJD	:=	${CMN_SRCD}
CMN_SRCD	:=	${addprefix ${SRCD}, ${CMN_SRCD}}
CMN_OBJD	:=	${addprefix ${OBJD}, ${CMN_OBJD}}

######################################
#            SOURCE FILES            #
######################################
SRV_SRCS	=	\
				lst.c				\
				main.c				\
				mt_get_clt.c		\
				mt_listen.c			\
				mt_lst_addback.c	\
				mt_lst_clear.c		\
				mt_lst_delone.c		\
				mt_quit.c

CLT_SRCS	=	\
				main.c			\
				mt_atopid.c		\
				mt_isdigit.c	\
				mt_isspace.c	\
				mt_talk.c

CMN_SRCS	=	\
				data.c			\
				mt_bzero.c		\
				mt_putbyte.c	\
				mt_putdata.c	\
				mt_putpid.c		\
				mt_strlen.c

######################################
#            OBJECT FILES            #
######################################
SRV_OBJS	=	${SRV_SRCS:.c=.o}
SRV_OBJS	:=	${addprefix ${SRV_OBJD}, ${SRV_OBJS}}

CLT_OBJS	=	${CLT_SRCS:.c=.o}
CLT_OBJS	:=	${addprefix ${CLT_OBJD}, ${CLT_OBJS}}

CMN_OBJS	=	${CMN_SRCS:.c=.o}
CMN_OBJS	:=	${addprefix ${CMN_OBJD}, ${CMN_OBJS}}

SRV_DEPS	=	${SRV_OBJS:.o=.d}
CLT_DEPS	=	${CLT_OBJS:.o=.d}
CMN_DEPS	=	${CMN_OBJS:.o=.d}

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

-include ${CMN_DEPS}

${CMN_OBJD}%.o:	${CMN_SRCD}%.c
	@${MAKEDIR} ${OBJD}
	@${MAKEDIR} ${CMN_OBJD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${CLT} ${SRV}

re:	fclean all

.PHONY:	all clean fclean re
