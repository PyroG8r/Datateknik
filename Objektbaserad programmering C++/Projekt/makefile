program: main.cpp maze.cpp 
	g++ -o main main.cpp maze.cpp -g

run: program
	./main
input: program
	./main --solve < maze.txt
output: program
	./main --solve < maze.txt > solution.txt
del: program
	rm main
