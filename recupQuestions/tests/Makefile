CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS= -L ../src/ -lpugixml
SRC= $(wildcard ../*.cpp) ../src/pugixml.cpp
OBJ= $(SRC:.cpp=.o)
TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cpp=.o)

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ $(LIBFLAGS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -I../ -o $@ -c $< $(LIBFLAGS)

clean :
	rm -f $(OBJ_TEST) testcase
