program: main.cpp maze.cpp menu.cpp
	g++ -o main main.cpp maze.cpp menu.cpp -g

run: program
	./main
input: program
	./main --solve < maze.txt
output: program
	./main --solve < maze.txt > solution.txt
del: program
	rm main
