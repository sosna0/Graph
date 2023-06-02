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

	auto& emIter = this->EmanatingEdgesIter(num);

	while (!emIter.IsDone()) {
		auto& edge = *emIter;

		if (&edge == nullptr) { return; } //zabezpieczenie przed sytuacj¹, gdy nie ma ¿adnych krawêdzi id¹cych od wierzcho³ka

		if (visited[edge.V1()->Number()] == false) {
			DFS1_vis(vis, edge.V1(), visited);
		}

		++emIter;
	}
	delete& emIter;

}


std::vector<int> GraphAsMatrix::DFS_Spanning_Tree(Vertex* v) {

	if (!this->IsConnected()) { return {}; }

	std::vector<bool> visited(this->NumberOfVertices(), false);
	std::vector<int> parent(this->NumberOfVertices());

	parent[v->Number()] = -1;

	DFS_Spanning_Tree_1(v, visited, parent);

	return parent;

}

void GraphAsMatrix::DFS_Spanning_Tree_1(Vertex* v, std::vector<bool> &visited, std::vector<int> &parent) {

	int num = v->Number();
	visited[num] = true;

	auto& emIter = this->EmanatingEdgesIter(num);

	while (!emIter.IsDone()) {
		auto& edge = *emIter;

		if (&edge == nullptr) { return; } //zabezpieczenie przed sytuacj¹, gdy nie ma ¿adnych krawêdzi id¹cych od wierzcho³ka

		int v1_number = edge.V1()->Number();

		if (visited[v1_number] == false) {
			parent[v1_number] = v->Number();
			//std::cout << v->Number() << " ";
			DFS_Spanning_Tree_1(edge.V1(), visited, parent);
		}

		++emIter;
	}
	delete& emIter;

}

