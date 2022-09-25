
build:
	clang++ -std=c++17 -o knight src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system

run:
	./knight

clean:
	rm knight
