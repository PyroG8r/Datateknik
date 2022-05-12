#pragma once

#include <array>
#include <stack>
#include <string>
#include "time.h"
#include <iostream>
class maze {
private:
	
	struct node {
		node();
		bool visited;
		bool neighborSouth;
		bool neighborNorth;
		bool neighborWest;
		bool neighborEast;
		bool openNorth;
		bool openSouth;
		bool openEast;
		bool openWest;

	};
	std::array<std::array<node, 3>, 3> labyrinth;
	
		


public:
	maze();
	bool UnvisitedNeighbor(int x, int y); //Kolla om det finns granne.
	bool isOpen(); //Kolla om det finns en �ppen v�g (senare)
	bool visited(); //Kolla om noden �r bes�kt
	void DFS(); //DFS
	void getNeighbor(int x, int y);
	std::string path(int x, int y);
	std::string open(int x, int y);
	
		

};



