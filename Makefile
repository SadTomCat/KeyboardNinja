# 1.$@ - берет из цели
# 2.$^ - берет из зависимости
COMPILATION = gcc -Wall -Werror
COMPILATION_TEST = gcc -I thirdparty -Wall -Werror
EXECUTABLE = ./bin/KeyboardNinja
OBJECTS = ./built/read_and_write.o ./built/profile.o ./built/menu.o ./built/rating.o ./built/scene.o ./built/training.o ./built/main.o ./built/comp_mode.o ./built/choice.o 

$(EXECUTABLE): $(OBJECTS)
	$(COMPILATION) -o $@ $^

./built/menu.o: ./src/menu.c
	$(COMPILATION) -o $@ -c $^

./built/read_and_write.o: ./src/read_and_write.c
	$(COMPILATION) -o $@ -c $^

./built/profile.o: ./src/profile.c
	$(COMPILATION) -o $@ -c $^

./built/rating.o: ./src/rating.c
	$(COMPILATION) -o $@ -c $^

./built/scene.o: ./src/scene.c
	$(COMPILATION) -o $@ -c $^

./built/training.o: ./src/training.c
	$(COMPILATION) -o $@ -c $^

./built/main.o: ./src/main.c
	$(COMPILATION) -o $@ -c $^

./built/comp_mode.o: ./src/comp_mode.c
	$(COMPILATION) -o $@ -c $^

./built/choice.o: ./src/choice.c
	$(COMPILATION) -o $@ -c $^

run: 
	./bin/KeyboardNinja

clean: 
	rm ./built/*.o
	rm ./bin/*
