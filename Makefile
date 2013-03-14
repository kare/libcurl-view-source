CFLAGS = -Wall -Werror -g
LDLIBS  = -lcurl
P = view-source
OBJECTS = view-source.o

$(P): $(OBJECTS)

clean:
	rm -f view-source *.o
run:
	./view-source http://www.reaktor.fi
