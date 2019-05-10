main: ./built/profile.o ./built/menu.o ./built/rating.o ./built/scene.o ./built/training.o ./built/read.o ./built/main.o ./built/comp_mode.o ./built/choice.o
	gcc -o ./bin/main ./built/menu.o ./built/profile.o ./built/rating.o ./built/scene.o ./built/training.o ./built/read.o ./built/main.o ./built/comp_mode.o ./built/choice.o

./built/menu.o: ./src/menu.c
	gcc -o ./built/menu.o -c ./src/menu.c

./built/read.o: ./src/read.c
	gcc -o ./built/read.o -c ./src/read.c

./built/profile.o: ./src/profile.c
	gcc -o ./built/profile.o -c ./src/profile.c

./built/rating.o: ./src/rating.c
	gcc -o ./built/rating.o -c ./src/rating.c

./built/scene.o: ./src/scene.c
	gcc -o ./built/scene.o -c ./src/scene.c

./built/training.o: ./src/training.c
	gcc -o ./built/training.o -c ./src/training.c

./built/main.o: ./src/main.c
	gcc -o ./built/main.o -c ./src/main.c

./built/comp_mode.o: ./src/comp_mode.c
	gcc -o ./built/comp_mode.o  -c ./src/comp_mode.c

./built/choice.o: ./src/choice.c
	gcc -o ./built/choice.o -c ./src/choice.c

run: ./bin/main
	./bin/main

clean: 
	rm ./built/*.o
	rm ./bin/*
