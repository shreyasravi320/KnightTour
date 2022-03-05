sfmlLib = /usr/local/lib/SFML -lsfml-graphics -lsfml-window -lsfml-system

build:
	clang++ -Ofast -std=c++17 -o KnightTour src/*.cpp -L $(sfmlLib) -I src/include -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment

run:
	./KnightTour

clean:
	rm KnightTour
