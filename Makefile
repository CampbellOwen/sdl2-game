OBJS = src/Game.cpp src/play.cpp src/mTexture.cpp src/Player.cpp

CC = g++

COMPILER_FLAGS = -g -std=c++11

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OBJ_NAME = game

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) 
