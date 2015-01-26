CC=clang
LDFLAGS= -I/usr/local/lib:/usr/lib
TEST_CFLAGS= -lcheck
TARGET_OBJS=$(wildcard bin/build/*.o)
TEST_TARGET_OBJS=$(wildcard bin/build/*.o)

all: 
	mkdir -p bin/build
	$(CC) -c src/midi_clock.c $(LDFLAGS) -o bin/build/midi_clock.o

install: all
	ar -cvq bin/libtiny-midi-clock.a $(TARGET_OBJS)
	sudo cp bin/libtiny-midi-clock.a /usr/lib

test:
	mkdir -p bin/test
	$(CC) tests/midi_clock_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/test/midi_clock_test

	./bin/test/midi_clock_test

clean: 
	rm -rf bin
