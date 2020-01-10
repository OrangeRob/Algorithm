TARGET = test
OBJ = main.o

%.o : %.cpp
	g++ -c -o $@ $<

all : ${OBJ}
	g++ -o ${TARGET} ${OBJ}

clean:
	rm -rf ${OBJ} ${TARGET}