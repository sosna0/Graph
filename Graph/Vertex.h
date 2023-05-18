#pragma once

#include <string>

class Vertex{
private:
	int number;
public:
	int weight;
	std::string label;
	Vertex(int n):number(n), weight(0){}
	int Number() const { return number; }
};

