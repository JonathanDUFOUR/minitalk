# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 22:30:33 by jodufour          #+#    #+#              #
#    Updated: 2021/11/09 17:46:23 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC			=	clang -c -o
LINK		=	clang -o
MKDIR		=	mkdir -p
RM			=	rm -rf

######################################
#             EXECUTABLE             #
######################################
CLT			=	client
SRV			=	server

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/
PRV_DIR		=	private/

SRV_SRC_DIR	:=	server/
SRV_OBJ_DIR	:=	${SRV_SRC_DIR}
SRV_SRC_DIR	:=	${addprefix ${SRC_DIR}, ${SRV_SRC_DIR}}
SRV_OBJ_DIR	:=	${addprefix ${OBJ_DIR}, ${SRV_OBJ_DIR}}

CLT_SRC_DIR	:=	client/
CLT_OBJ_DIR	:=	${CLT_SRC_DIR}
CLT_SRC_DIR	:=	${addprefix ${SRC_DIR}, ${CLT_SRC_DIR}}
CLT_OBJ_DIR	:=	${addprefix ${OBJ_DIR}, ${CLT_OBJ_DIR}}

CMN_SRC_DIR	:=	common/
CMN_OBJ_DIR	:=	${CMN_SRC_DIR}
CMN_SRC_DIR	:=	${addprefix ${SRC_DIR}, ${CMN_SRC_DIR}}
CMN_OBJ_DIR	:=	${addprefix ${OBJ_DIR}, ${CMN_OBJ_DIR}}

######################################
#            SOURCE FILES            #
######################################
SRV_SRC		=	\
				main.c			\
				mt_listen.c		\
				mt_quit.c

CLT_SRC		=	\
				main.c			\
				mt_talk.c

CMN_SRC		=	\
				${addprefix data/,	\
					mt_data_get.c	\
					mt_data_init.c	\
					mt_data_print.c	\
				}					\
				mt_atopid.c			\
				mt_bzero.c			\
				mt_isdigit.c		\
				mt_isspace.c		\
				mt_putpid.c			\
				mt_strlen.c

######################################
#            OBJECT FILES            #
######################################
SRV_OBJ		=	${SRV_SRC:.c=.o}
SRV_OBJ		:=	${addprefix ${SRV_OBJ_DIR}, ${SRV_OBJ}}

CLT_OBJ		=	${CLT_SRC:.c=.o}
CLT_OBJ		:=	${addprefix ${CLT_OBJ_DIR}, ${CLT_OBJ}}

CMN_OBJ		=	${CMN_SRC:.c=.o}
CMN_OBJ		:=	${addprefix ${CMN_OBJ_DIR}, ${CMN_OBJ}}

SRV_DEP		=	${SRV_OBJ:.o=.d}
CLT_DEP		=	${CLT_OBJ:.o=.d}
CMN_DEP		=	${CMN_OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-MMD -MP
CFLAGS		+=	-I${PRV_DIR}

LDFLAGS		=	

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################

all:	${SRV} ${CLT}

${SRV}:	${SRV_OBJ} ${CMN_OBJ}
	${LINK} $@ ${LDFLAGS} $^

${CLT}:	${CLT_OBJ} ${CMN_OBJ}
	${LINK} $@ ${LDFLAGS} $^

-include ${SRV_DEP}
-include ${CLT_DEPS}
-include ${CMN_DEPS}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${CLT} ${SRV}

re:	fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

.PHONY:	all clean fclean re
