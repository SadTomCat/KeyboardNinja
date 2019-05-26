# 1.$@ - берет из цели
# 2.$^ - берет из зависимости
CC = gcc
CFLAGS = -Wall -Werror
CFLAGS_TEST = -I thirdparty -Wall -Werror
EXECUTABLE = ./bin/KeyboardNinja
OBJECTS = ./built/read_and_write.o ./built/profile.o ./built/menu.o ./built/rating.o ./built/scene.o ./built/training.o ./built/main.o ./built/comp_mode.o ./built/choice.o 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

./built/menu.o: ./src/menu.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/read_and_write.o: ./src/read_and_write.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/profile.o: ./src/profile.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/rating.o: ./src/rating.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/scene.o: ./src/scene.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/training.o: ./src/training.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/main.o: ./src/main.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/comp_mode.o: ./src/comp_mode.c
	$(CC) $(CFLAGS)  -o $@ -c $^

./built/choice.o: ./src/choice.c
	$(CC) $(CFLAGS)  -o $@ -c $^

run: 
	./bin/KeyboardNinja

clean: 
	rm ./built/*.o
	rm ./bin/*
