CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g -I src/
LIBFLAGS= -L src/ -lpugixml
SRC= $(wildcard *.cpp) src/pugixml.cpp
OBJ= $(SRC:.cpp=.o)
TST_DIR=tests/
TST= $(wildcard $(TST_DIR)/*.cpp)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC= projet


all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

test : testcase
	cd $(TST_DIR); ./testcase

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(LIBS)

.depends:
	g++ -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest
