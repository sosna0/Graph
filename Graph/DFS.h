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

		if (edge.V0() == nullptr || edge.V1() == nullptr) { return; }
		//std::cout << "Edge(" << edge.V0()->Number() << ", " << edge.V1()->Number() << ")" << std::endl;

		if (visited[edge.V1()->Number()] == false) {
			DFS1(edge.V1(), visited);
		}

		++emIter;
	}
	delete& emIter;

}