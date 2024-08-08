# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 17:03:09 by bepoisso          #+#    #+#              #
#    Updated: 2024/08/07 18:28:06 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
WFLAGS=-Wall -Wextra -Werror
GFLAGS=-g
GDBFLAGS=-tui -q
SRC= ./srcs/
INC= ./includes/
EXEC= $(CC) $(WFLAGS)
GDB= gdb $(GDBFLAGS) a.out
ADD=git add -A
COM=git commit -m "**GIT AUTO-PUSH**"
PUSH=git push

all:
	$(EXEC) $(SRC)*.c main.c

clean:
	rm -rf *.o *.out *.swp *.gch

debug :
	$(EXEC) debug.c $(SRC)*.c

gdb:
	$(CC) $(SRC)*.c main.c -I $(INC)*.h $(GFLAGS) && $(GDB)

gdbug:
	$(CC) $(SRC)*.c debug.c -I $(INC)*.h $(GFLAGS) && $(GDB)

git:
	$(ADD) && $(COM) && $(PUSH)

noflag:
	$(CC) $(SRC)*.c main.c -I $(INC)*.h

.PHONY: all debug gdb gdbug git noflag clean
