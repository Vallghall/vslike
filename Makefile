ROOT=$(shell pwd)
CFLAGS= -Wall -O2
INCLUDES= -I ./include/
LIBS= -L ./lib/ -lraylib

ifeq ($(shell uname),Darwin)
	LIBS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
endif

all: bin vslike

.PHONY: vslike
	
vslike: *.o
	cc -o ./bin/$@ $(CFLAGS) $(LIBS) $^

%.o: %.c ./src/%.h
	cc $(CFLAGS) $(INCLUDES) -c $^

clean:
	rm *.o

bin:
	mkdir $@

# ==== dependencies ====

raylib: lib include
	cd ./vendor/raylib-5.0/src && \
	make PLATFORM=PLATFORM_DESKTOP && \
	ln -sf $@.h $(ROOT)/include/$@.h && \
	mv lib$@.a $(ROOT)/lib/ && \
	rm *.o

include:
	mkdir $@

lib:
	mkdir $@
