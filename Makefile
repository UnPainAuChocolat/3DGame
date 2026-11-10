#-----------------------------------[Variables]-----------------------------------

NAME= game

CC= g++

SRC=	main.cpp\
			game.cpp\
			Player/player.cpp\
			Level/world.cpp

FLAG= -Wall -Wextra -Werror

#---------------------------------------[Func]-------------------------------------

all:
	$(CC) $(FLAG) $(SRC) -lraylib -o $(NAME)

#---------------------------------------[PHONY]------------------------------------

.PHONY: all

