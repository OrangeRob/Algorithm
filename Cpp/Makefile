TARGET = test
OBJ = main.o

CXXFLAGS = -I.

%.o : %.cpp
	g++ -c -o $@ $< ${CXXFLAGS}

all : ${OBJ}
	g++ -o ${TARGET} ${OBJ} ${CXXFLAGS}

clean:
	rm -rf ${OBJ} ${TARGET}
