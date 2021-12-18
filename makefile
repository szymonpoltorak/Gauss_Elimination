FLAGS = -Wall -pedantic -Wextra
CCO = cc -c

matrix: main.o gauss.o backsubst.o mat_io.o
	$(CC) $^ -o $@
	mv *.o src/*.gch bin/

main.o: src/main.c src/gauss.h src/backsubst.h src/mat_io.h
	$(CCO) $^ $(FLAGS)

gauss.o: src/gauss.c src/gauss.h src/mat_io.h
	$(CCO) $^ $(FLAGS) -lm

backsubst.o: src/backsubst.c src/backsubst.h
	$(CCO) $^ $(FLAGS)

mat_io.o: src/mat_io.c src/mat_io.h
	$(CCO) $^ $(FLAGS)
test: test_gauss.o gauss.o backsubst.o mat_io.o
	$(CC) $^ -o $@
	mv *.o src/*.gch bin/
test_gauss.o: src/test_gauss.c src/gauss.h src/backsubst.h src/mat_io.h
	$(CCO) $^ $(FLAGS) -lm
clean:
	rm bin/*.o bin/*.gch matrix
