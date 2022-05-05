CC 		= icc
CFLAGS		= 

all: clean serial parallel 

serial:  pi.c 
	${CC} -O0 -openmp ${CFLAGS} pi.c -o serial

parallel:  pi_omp.c 
	${CC} -O0 -openmp ${CFLAGS}  pi_omp.c -o parallel

clean:
	 rm -f *.o  serial parallel a.out

