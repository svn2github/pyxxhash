CC		= gcc
CFLAGS	= -fpic -c
INCLUDE	= -I/usr/include/python2.7
RM		= rm -fr

all: pyxxhash
pyxxhash:  pyxxhash.o xxhash.o
		$(CC)  -o pyxxhash.so --shared  $?
xxhash.o:
		$(CC) ${CFLAGS} -o $@ xxhash.c 
pyxxhash.o:
	  	$(CC) ${CFLAGS} -o $@ pyxxhash.c $(INCLUDE)
clean	:
		$(RM) *.o *.so
