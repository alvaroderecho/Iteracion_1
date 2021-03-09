CFLAGS = -g -Wall -pedantic
CC = gcc

exe: game_loop.o graphic_engine.o game.o screen.o space.o command.o game_reader.o object.o player.o
	$(CC) $(CFLAGS) -oexe game_loop.o graphic_engine.o game.o screen.o space.o command.o game_reader.o object.o player.o

game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h types.h object.h player.h screen.h game_reader.h
	$(CC) $(CFLAGS) -c game_loop.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h object.h player.h screen.h
	$(CC) $(CFLAGS) -c graphic_engine.c

game.o: game.c game.h command.h space.h types.h object.h player.h
	$(CC) $(CFLAGS) -c game.c

game_reader.o: game_reader.c game_reader.h game.h command.h space.h types.h object.h player.h
	$(CC) $(CFLAGS) -c game_reader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

screen.o: screen.c screen.h
	$(CC) $(CFLAGS) -c screen.c

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c space.c

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c player.c

set_test: set_test.o set.o
	$(CC) $(CFLAGS) -oset_test set_test.o set.o

set_test.o: set_test.c set_test.h test.h set.h types.h
	$(CC) $(CFLAGS) -c set_test.c

die_test: die_test.o die.o
	$(CC) $(CFLAGS) -odie_test die_test.o die.o

die_test.o: die_test.c die_test.h test.h die.h
	$(CC) $(CFLAGS) -c die_test.c

space_test: space_test.o space.o
	$(CC) $(CFLAGS) -ospace_test space_test.o space.o

space_test.o: space_test.c space_test.h test.h space.h
	$(CC) $(CFLAGS) -c space_test.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

clean:
	@echo "Cleaning: "
	rm -rf *.o exe space_test die_test set_test
