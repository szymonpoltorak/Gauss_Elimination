FLAGS = -Wall -pedantic -Wextra -O3
MFLAGS = -Wall -pedantic -Wextra -lm -O3
TFLAGS = -Wall -pedantic -Wextra -DTEST -O3
CCC = cc -c
CCO = cc -o
MBIN = -mkdir bin
MVBIN = -mv *.o bin/
DEL = -rm bin/*.o matrix test

matrix: main.o gauss.o backsubst.o mat_io.o
	$(CCO) $@ $^
	$(MBIN)
	$(MVBIN)

main.o: src/main.c src/gauss.h src/backsubst.h src/mat_io.h
	$(CCC) $< $(FLAGS)

gauss.o: src/gauss.c src/gauss.h src/mat_io.h
	$(CCC) $< $(MFLAGS)

backsubst.o: src/backsubst.c src/backsubst.h
	$(CCC) $< $(FLAGS)

mat_io.o: src/mat_io.c src/mat_io.h
	$(CCC) $< $(FLAGS)

test: test_gauss.o gauss.o backsubst.o mat_io_test.o
	$(CCO) $@ $^
	$(MBIN)
	$(MVBIN)

mat_io_test.o: src/mat_io.c src/mat_io.h
	$(CCC) $< -o $@ $(TFLAGS)	

test_gauss.o: src/test_gauss.c src/gauss.h src/backsubst.h src/mat_io.h
	$(CCC) $< $(MFLAGS)

clean:
	$(DEL)
