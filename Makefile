##
## Makefile for Makefile in /home/weber_i/rendu/CPE_2014_bsq
## 
## Made by Clément Weber
## Login   <weber_i@epitech.net>
## 
## Started on  Sat Jun 20 23:49:37 2015 Clément Weber
## Last update Sat Jun 20 23:51:02 2015 Clément Weber
##

NAME            = msh

CC              = clang

CFLAGS          = -Wall -Wextra -std=c99 -O0

DEBUGFLAG       = -g

RM              = rm -rf

SRCS            = main.c\
				  tools.c\
				  shell.c\
				  prompt.c\
				  builtins.c\
				  path.c

OBJ             = $(SRCS:.c=.o)

all: $(NAME)

debug:
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS) $(DEBUGFLAG)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: fclean clean all re
