CFLAGS = -g -Wall -pedantic
CC = gcc

exe: game_loop.o graphic_engine.o game.o screen.o space.o command.o game_reader.o object.o player.o set.o die.o link.o inventory.o
	$(CC) $(CFLAGS) -oexe game_loop.o graphic_engine.o game.o screen.o space.o command.o game_reader.o object.o player.o set.o die.o link.o inventory.o

game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h types.h object.h player.h screen.h game_reader.h
	$(CC) $(CFLAGS) -c game_loop.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h object.h player.h screen.h inventory.h
	$(CC) $(CFLAGS) -c graphic_engine.c

game.o: game.c game.h command.h space.h types.h object.h player.h set.h inventory.h
	$(CC) $(CFLAGS) -c game.c

game_reader.o: game_reader.c game_reader.h game.h command.h space.h types.h object.h player.h link.h inventory.h
	$(CC) $(CFLAGS) -c game_reader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

screen.o: screen.c screen.h
	$(CC) $(CFLAGS) -c screen.c

space.o: space.c space.h types.h set.h link.h
	$(CC) $(CFLAGS) -c space.c

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

player.o: player.c player.h types.h inventory.h
	$(CC) $(CFLAGS) -c player.c

set_test: set_test.o set.o
	$(CC) $(CFLAGS) -oset_test set_test.o set.o

set_test.o: set_test.c set_test.h test.h set.h types.h
	$(CC) $(CFLAGS) -c set_test.c

die_test: die_test.o die.o
	$(CC) $(CFLAGS) -odie_test die_test.o die.o

die_test.o: die_test.c die_test.h test.h die.h
	$(CC) $(CFLAGS) -c die_test.c

space_test: space_test.o space.o set.o
	$(CC) $(CFLAGS) -ospace_test space_test.o space.o set.o

space_test.o: space_test.c space_test.h test.h space.h set.h
	$(CC) $(CFLAGS) -c space_test.c

inventory_test: inventory_test.o inventory.o set.o
	$(CC) $(CFLAGS) -oinventory_test inventory_test.o inventory.o set.o

inventory_test.o: inventory_test.c inventory_test.h test.h inventory.h set.h
	$(CC) $(CFLAGS) -c inventory_test.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

die.o: die.c die.h types.h
	$(CC) $(CFALGS) -c die.c

link.o: link.c link.h types.h
	$(CC) $(CFALGS) -c link.c

inventory.o: inventory.c inventory.h types.h set.h
	$(CC) $(CFALGS) -c inventory.c

link_test: link_test.o link.o
	$(CC) $(CFLAGS) -olink_test link_test.o link.o

link_test.o: link_test.c link_test.h link.h types.h test.h
	$(CC) $(CFLAGS) -c link_test.c

clean:
	@echo "Cleaning: "
	rm -rf *.o exe space_test die_test set_test link_test
