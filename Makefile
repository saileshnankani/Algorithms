all : ./sorting/sorting.o ./heap/heap.o

CXX = g++
CXXFLAGS = -g -std=c++14
EXEC = algorithms
OBJECTS = ./sorting/sorting.o ./heap/heap.o
DEPENDS = ${OBJECTS.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -Wall -MMD  

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

