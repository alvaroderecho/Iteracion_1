CFLAGS = -g -Wall -pedantic
CC = gcc
OBJ = obj/
SRC = src/
INC = inlcudes/

exe: $(OBJ)game_loop.o $(OBJ)graphic_engine.o $(OBJ)game.o $(OBJ)screen.o $(OBJ)space.o $(OBJ)command.o $(OBJ)game_reader.o $(OBJ)object.o $(OBJ)player.o $(OBJ)set.o $(OBJ)die.o $(OBJ)link.o $(OBJ)inventory.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)game_loop.o:
	$(CC) $(CFLAGS) -c $(SRC)game_loop.c -I includes -o $@

$(OBJ)graphic_engine.o:
	$(CC) $(CFLAGS) -c $(SRC)graphic_engine.c -I includes -o $@

$(OBJ)game.o: 
	$(CC) $(CFLAGS) -c $(SRC)game.c -I includes -o $@

$(OBJ)game_reader.o:
	$(CC) $(CFLAGS) -c $(SRC)game_reader.c -I includes -o $@

$(OBJ)object.o:
	$(CC) $(CFLAGS) -c $(SRC)object.c -I includes -o $@

$(OBJ)screen.o:
	$(CC) $(CFLAGS) -c $(SRC)screen.c -I includes -o $@

$(OBJ)space.o:
	$(CC) $(CFLAGS) -c $(SRC)space.c -I includes -o $@

$(OBJ)command.o:
	$(CC) $(CFLAGS) -c $(SRC)command.c -I includes -o $@

$(OBJ)player.o:
	$(CC) $(CFLAGS) -c $(SRC)player.c -I includes -o $@

$(OBJ)set.o:
	$(CC) $(CFLAGS) -c $(SRC)set.c -I includes -o $@

$(OBJ)die.o:
	$(CC) $(CFLAGS) -c $(SRC)die.c -I includes -o $@

$(OBJ)link.o:
	$(CC) $(CFLAGS) -c $(SRC)link.c -I includes -o $@

$(OBJ)inventory.o:
	$(CC) $(CFLAGS) -c $(SRC)inventory.c -I includes -o $@

link_test: $(OBJ)link_test.o $(OBJ)link.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)link_test.o:
	$(CC) $(CFLAGS) -c $(SRC)link_test.c -I includes -o $@

set_test: $(OBJ)set_test.o $(OBJ)set.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)set_test.o:
	$(CC) $(CFLAGS) -c $(SRC)set_test.c -I includes -o $@

die_test: $(OBJ)die_test.o $(OBJ)die.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)die_test.o:
	$(CC) $(CFLAGS) -c $(SRC)die_test.c -I includes -o $@

space_test: $(OBJ)space_test.o $(OBJ)space.o $(OBJ)set.o $(OBJ)link.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)space_test.o:
	$(CC) $(CFLAGS) -c $(SRC)space_test.c -I includes -o $@

inventory_test: $(OBJ)inventory_test.o $(OBJ)inventory.o $(OBJ)set.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)inventory_test.o:
	$(CC) $(CFLAGS) -c $(SRC)inventory_test.c -I includes -o $@

player_test: $(OBJ)player_test.o $(OBJ)player.o $(OBJ)inventory.o $(OBJ)set.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)player_test.o:
	$(CC) $(CFLAGS) -c $(SRC)player_test.c -I includes -o $@

object_test: $(OBJ)object_test.o $(OBJ)object.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)object_test.o:
	$(CC) $(CFLAGS) -c $(SRC)object_test.c -I includes -o $@

.PHONY: clean
clean:
	@echo "Cleaning: "
	rm -rf obj/*.o exe space_test die_test set_test link_test inventory_test player_test object_test
