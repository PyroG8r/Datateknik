#include "node.h"
#include <array>
#include <stack>
#include <string>
#include "time.h"
#include <iostream>
#include <vector>

maze::maze() {
	srand(time(NULL));
	std::array<std::array<node,3>,3> labyrinth;
	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			labyrinth[x][y] = node();
			getNeighbor(x, y);
			
		}
	}
	
	
}

maze::node::node() {
	 visited = 0;
	 neighborSouth = 0;
	 neighborNorth = 0;
	 neighborWest = 0;
	 neighborEast = 0;
     openEast = 0;
	 openSouth = 0;
	 openNorth = 0;
	 openWest = 0;

}
void maze::DFS() {
	int x = 0, y = 0;
	node current = labyrinth[x][y];
	node neighbor;
	std::stack<node> stack;
	current.visited = 1;
	stack.push(current);


	if (!stack.empty()) {
		current = stack.top();
		stack.pop();
		
		if (UnvisitedNeighbor(x, y) == true) {
			std::cout << "X: " << x << "Y: " << y << std::endl;
			stack.push(current);
			open(x, y);
			if (open(x, y) == "EAST") {
				neighbor = labyrinth[x + 1][y];
				neighbor.visited = 1;
				stack.push(neighbor);
			}
			else if (open(x, y) == "WEST") {
				neighbor = labyrinth[x - 1][y];
				neighbor.visited = 1;
				stack.push(neighbor);
			}
			else if (open(x, y) == "NORTH") {
				neighbor = labyrinth[x][y - 1];
				neighbor.visited = 1;
				stack.push(neighbor);
			}
			else if (open(x, y) == "SOUTH") {
				neighbor = labyrinth[x][y + 1];
				neighbor.visited = 1;
				stack.push(neighbor);
			}
			
		}


	}

}

void maze::getNeighbor(int x, int y) {
	int checkxWest = x - 1;
	int checkySouth = y + 1;
	int checkxEast = x + 1;
	int checkyNorth = y - 1;

	if (checkxWest >= 0) {
		labyrinth[x][y].neighborWest = 1;
	}
	if (checkxEast <= 2) {
		labyrinth[x][y].neighborEast = 1;
	}
	if (checkySouth >= 2) {
		labyrinth[x][y].neighborNorth = 1;
	}
	if (checkyNorth <= 0) {
		labyrinth[x][y].neighborSouth = 1;

	}
}
bool maze::UnvisitedNeighbor(int x, int y) {
	node current = labyrinth[x][y];
	
	if (current.neighborEast == 1) {
		node east = labyrinth[x + 1][y];
		if (east.visited == 0)
			return true;
	}

	if (current.neighborWest == 1) {
		node west = labyrinth[x - 1][y];
		if (west.visited == 0) {
			return true;
		}
	}

	if (current.neighborSouth == 1) {
		node south = labyrinth[x][y + 1];
		if (south.visited == 0) {
			return true;
		}
	}

	if (current.neighborNorth == 1) {
		node north = labyrinth[x][y - 1];
		if (north.visited == 0) {
			return true;
		}
	
	}
	return false;
}

std::string maze::path(int x, int y) {

	node current = labyrinth[x][y];
	std::vector<std::string> way;
	int many;
	int random = 0;
	std::string choice;
	if (UnvisitedNeighbor(x,y) == true) {

		if (current.neighborEast == 1 && current.visited == 0) {
			way.push_back("EAST");
		}
		if (current.neighborNorth == 1 && current.visited == 0) {
			way.push_back("NORTH");

		}
		if (current.neighborSouth == 1 && current.visited == 0) {
			way.push_back("SOUTH");

		}
		if (current.neighborWest == 1 && current.visited == 0) {
			way.push_back("WEST");

		}
	}
	many =  way.size();
	random = rand() %many;
	choice = way[random];

	return choice;
	
}

std::string maze::open(int x, int y) {
	node current = labyrinth[x][y];
	node east = labyrinth[x + 1][y];
	node west = labyrinth[x - 1][y];
	node south = labyrinth[x][y + 1];
	node north = labyrinth[x][y - 1];
	
	if (path(x,y) == "EAST") {
		current.openEast = 1;
		east.openWest = 1;
		return "EAST";

	}
	 else if (path(x, y) == "WEST") {
		current.openWest = 1;
		west.openEast = 1;
		return "WEST";
	}
	else if (path(x, y) == "SOUTH") {
		current.openSouth = 1;
		south.openNorth = 1;
		return "SOUTH";
	}
	else if (path(x, y) == "NORTH") {
		current.openNorth = 1;
		north.openSouth = 1;
		return "NORTH";
	}

}

