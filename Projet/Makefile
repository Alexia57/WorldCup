CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBS= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC= main


all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(LIBS)


clean:
	rm -f $(OBJ) $(EXEC) *.*~
