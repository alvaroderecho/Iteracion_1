CFLAGS = -g -Wall -pedantic
CC = gcc

exe: game_loop.o graphic_engine.o game.o screen.o space.o command.o game_reader.o object.o player.o set.o die.o link.o inventory.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

game_loop.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

graphic_engine.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

game.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

game_reader.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

object.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

screen.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

space.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

command.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

player.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

set.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

die.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

link.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

inventory.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

link_test: link_test.o link.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

link_test.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

set_test: set_test.o set.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

set_test.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

die_test: die_test.o die.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

die_test.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

space_test: space_test.o space.o set.o link.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

space_test.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

inventory_test: inventory_test.o inventory.o set.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

inventory_test.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

player_test: player_test.o player.o inventory.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

player_test.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

object_test: object_test.o object.o
	$(CC) $(CFLAGS) -o $@ $(addprefix obj/, $^)

object_test.o:
	$(CC) $(CFLAGS) -c $(addprefix src/, $(addsuffix .c, $(basename $@))) -I includes -o $(addprefix obj/, $@)

clean:
	@echo "Cleaning: "
	rm -rf *.o exe space_test die_test set_test link_test inventory_test player_test object_test
