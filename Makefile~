#OBJS specifies which files to compile as part of the project
#OBJS=21_sound_effects_and_music.cpp
OBJS=music.cpp
#CC specifies which compiler w're using
CC=g++

#COMPILER_FLAGS specifies the additional compilation options we're using
#-w supresses all warnings
COMPILER_FLAGS=-w

#LINKER_FLAGS specifies the libraries we're linking against
#LINKER_FLAGS= -lSDL2 -lSDL2_image -lSDL2_mixer
LINKER_FLAGS= -lSDL2  -lSDL2_mixer

#OBJ_NAME specifies the name of our exectuable
#OBJ_NAME=21_sound_effects_and_music
OBJ_NAME=music

#this is the target that compiles our executable
all:$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


