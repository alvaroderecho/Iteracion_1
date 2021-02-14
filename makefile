exe: game_loop.o graphic_engine.o game.o screen.o space.o command.o game_reader.o
	gcc -oexe game_loop.o graphic_engine.o game.o screen.o space.o command.o game_reader.o

game_loop.o: game_loop.c graphic_engine.h
	gcc -c game_loop.c

graphic_engine.o: graphic_engine.c graphic_engine.h command.h screen.h
	gcc -c graphic_engine.c

game.o: game.c game.h
	gcc -c game.c

game_reader.o: game_reader.c game_reader.h
	gcc -c game_reader.c
	
screen.o: screen.c screen.h
	gcc -c screen.c

space.o: space.c space.h types.h
	gcc -c space.c

command.o: command.c command.h
	gcc -c command.c

clean:
	@echo "Cleaning: "
	rm -rf *.o exe
