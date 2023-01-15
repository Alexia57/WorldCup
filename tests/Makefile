CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBS= -I ../lib/pugixml/ -lsfml-graphics -lsfml-window -lsfml-system
LIBFLAGS= -L ../lib/pugixml/ -lpugixml
SRC= $(filter-out ../src/main.cpp, $(wildcard ../src/*.cpp)) ../lib/pugixml/pugixml.cpp
OBJ= $(SRC:.cpp=.o)
SRC_TEST= $(wildcard *.cpp)
OBJ_TEST = $(OBJ) $(SRC_TEST:.cpp=.o)

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(LIBS)

clean :
	rm -f $(OBJ_TEST) testcase
