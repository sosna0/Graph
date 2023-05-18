#pragma once

#include <iostream>
#include <vector>



void GraphAsMatrix::DFS(Vertex* v) {

	std::vector<bool> visited(this->NumberOfVertices(), false);
	DFS1(v, visited);

}


void GraphAsMatrix::DFS1(Vertex* v, std::vector<bool>& visited) {

	int num = v->Number();
	std::cout << "Vertex: " << num << std::endl;
	visited[num] = true;

	auto& emIter = this->EmanatingEdgesIter(num);

	while (!emIter.IsDone()) {
		auto& edge = *emIter;

		if (&edge == nullptr) { return; } //zabezpieczenie przed sytuacj�, gdy nie ma �adnych kraw�dzi id�cych od wierzcho�ka

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

	auto& emIter = this->EmanatingEdgesIter(num);

	while (!emIter.IsDone()) {
		auto& edge = *emIter;

		if (&edge == nullptr) { return; } //zabezpieczenie przed sytuacj�, gdy nie ma �adnych kraw�dzi id�cych od wierzcho�ka

		if (visited[edge.V1()->Number()] == false) {
			DFS1_vis(vis, edge.V1(), visited);
		}

		++emIter;
	}
	delete& emIter;

}
