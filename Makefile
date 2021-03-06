##
## Makefile for my_ftp in /srv/http
## 
## Made by Adolfo Flores
## Login   <flores_a@epitech.eu>
## 
## Started on  Sat Mar 21 14:44:31 2015 
## Last update Thu Apr  2 11:36:58 2015 
##

CLNT_SRC =		clnt/main.c \
				clnt/client.c \
				clnt/auth_cmds.c \
				clnt/commands.c \
				clnt/connection_commands.c \
				clnt/responses.c \
				clnt/active_mode.c \
				clnt/get_data.c \
				clnt/send_data.c \
				clnt/extra.c \

SRVR_SRC =		server/main.c \
				server/server.c \
				server/actions.c \
				server/active_mode.c \
				server/do_actions.c \

CLNT_OBJ =		$(CLNT_SRC:.c=.o)

SRVR_OBJ =		$(SRVR_SRC:.c=.o)

DEPS =		include/defs.h

SRVR =		serveur

CLNT =		client

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra -pedantic

RM =		rm -f

all:		$(SRVR) $(CLNT)

$(SRVR):	$(SRVR_OBJ) $(DEPS)
			gcc $(CFLAGS) -o $(SRVR) $(SRVR_OBJ)

$(CLNT):	$(CLNT_OBJ) $(DEPS)
			gcc $(CFLAGS) -o $(CLNT) $(CLNT_OBJ)
clean:
			$(RM) $(SRVR_OBJ) $(CLNT_OBJ)

fclean:		clean
			$(RM) $(SRVR) $(CLNT)

re:			fclean all

.PHONY:			all clean fclean re
