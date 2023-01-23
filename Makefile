CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g 
LIBS =  -lsfml-graphics -lsfml-window -lsfml-system
LIBFLAGS= -L lib/pugixml/ -lpugixml 
SRC= $(wildcard src/*.cpp) lib/pugixml/pugixml.cpp
OBJ= $(SRC:.cpp=.o)
TST_DIR=tests/
TST= $(wildcard $(TST_DIR)/*.cpp)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC= projet


all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

checkout : testcase
	cd $(TST_DIR); ./testcase

$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(LIBS)

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest

