# 1.$@ - берет из цели
# 2.$^ - берет из зависимости
CC = gcc
CFLAGS = -Wall -Werror
CFLAGS_TEST = -I thirdparty -Wall -Werror
EXECUTABLE = ./bin/KeyboardNinja
EXECUTABLE_TEST = ./bin/test
OBJECTS = ./built/read_and_write.o ./built/profile.o ./built/menu.o ./built/rating.o ./built/scene.o ./built/training.o ./built/main.o ./built/comp_mode.o ./built/choice.o 
OBJECTS_TEST = ./built/read_and_write.o ./built/profile.o ./built/menu.o ./built/rating.o ./built/scene.o ./built/training.o ./built/test/main.o ./built/comp_mode.o ./built/choice.o ./built/test/tests.o 

all: support_files bin/KeyboardNinja bin/test
.PHONY: support_files run run_test clean

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

$(EXECUTABLE_TEST): $(OBJECTS_TEST)
	$(CC) $(CFLAGS_TEST) -o $@ $^

./built/test/main.o: ./test/main.c
	$(CC) $(CFLAGS_TEST) -o $@ -c $^

./built/test/tests.o: ./test/tests.c
	$(CC) $(CFLAGS_TEST) -o $@ -c $^

support_files: 
	touch ./data/PROFILES.txt
	touch ./data/RATING.txt

run: 
	./bin/KeyboardNinja

run_test: 
	./bin/test

clean: 
	rm ./built/*.o
	rm ./built/test/*.o
	rm ./bin/*
	rm ./data/RATING.txt 
	rm ./data/PROFILES.txt