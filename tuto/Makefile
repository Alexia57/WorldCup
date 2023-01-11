CC=g++
CCFLAGS= -Wall -Werror 
LIBS= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC= projet


all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(LIBS)


clean:
	rm -f $(OBJ) $(EXEC) *.*~
