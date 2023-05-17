#pragma once

#include "GraphAsMatrix.h"
#include <iostream>
#include <vector>



void GraphAsMatrix::DFS(Vertex* v) {

	std::vector<bool> visited(this->NumberOfVertices(), false);

	DFS1(v, visited);

}


void GraphAsMatrix::DFS1(Vertex* v, std::vector<bool>& visited) {

	std::cout << "Vertex: " << v->Number() << std::endl;
	visited[v->Number()] = true;

	auto& emIter = this->EmanatingEdgesIter(v->Number());

	while (!emIter.IsDone()) {
		auto& edge = *emIter;

		if (&edge == nullptr) { return; } //zabezpieczenie przed sytuacj¹, gdy nie ma ¿adnych krawêdzi id¹cych od wierzcho³ka

		if (visited[edge.V1()->Number()] == false) {
			DFS1(edge.V1(), visited);
		}

		++emIter;
	}
	delete& emIter;

}

void GraphAsMatrix::DFS_vis(Visitor<int>* vis, Vertex* v) {

	std::vector<bool> visited(this->NumberOfVertices(), false);
	vis->SetAll();
	DFS1_vis(vis, v, visited);

}


void GraphAsMatrix::DFS1_vis(Visitor<int>* vis, Vertex* v, std::vector<bool>& visited) {

	//std::cout << "Vertex: " << v->Number() << std::endl;
	int num = v->Number();
	vis->Visit(num);

	visited[num] = true;

	auto& emIter = this->EmanatingEdgesIter(v->Number());

	while (!emIter.IsDone()) {
		auto& edge = *emIter;

		if (&edge == nullptr) { return; } //zabezpieczenie przed sytuacj¹, gdy nie ma ¿adnych krawêdzi id¹cych od wierzcho³ka

		if (visited[edge.V1()->Number()] == false) {
			DFS1(edge.V1(), visited);
		}

		++emIter;
	}
	delete& emIter;

}