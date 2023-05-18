#include <iostream>
#include "GraphAsMatrix.h"
#include "CountingVisitor.h"
#include "WritingVisitor.h"
#include "DFS.h"

#define TEST 1 //1, 2, 3 lub 4

int main() {

#if TEST == 1

	GraphAsMatrix graph(10, true);	//powtórzyc dla grafu nieskierowanego

	std::cout << "Number of vertices: " << graph.NumberOfVertices() << std::endl;
	std::cout << "Number of edges: " << graph.NumberOfEdges() << std::endl << std::endl;

	auto vertex = graph.SelectVertex(2);
	std::cout << "Unique vertex(2) number: " << vertex->Number() << std::endl;

	vertex->weight = 2;
	std::cout << "Vertex weight: " << vertex->weight << std::endl << std::endl;


	//------------------------------------------------
	graph.AddEdge(1, 2); std::cout << "AddEdge(1, 2)" << std::endl;
	graph.AddEdge(1, 2); std::cout << "AddEdge(1, 2)" << std::endl;

	graph.AddEdge(2, 3); std::cout << "AddEdge(2, 3)" << std::endl;
	graph.AddEdge(3, 4); std::cout << "AddEdge(3, 4)" << std::endl;
	graph.AddEdge(9, 9); std::cout << "AddEdge(9, 9)" << std::endl << std::endl;


	//------------------------------------------------
	
	/*std::cout << "\nAdjacency matrix : \n\n";

	for (int i = 0; i < graph.NumberOfVertices(); i++) {
		for (int j = 0; j < graph.NumberOfVertices(); j++) {
			std::cout << graph.IsEdge(i,j) << " ";
		}
		std::cout << std::endl;
	}
	*/

	//------------------------------------------------
	std::cout << "Number of vertices: " << graph.NumberOfVertices() << std::endl;
	std::cout << "Number of edges: " << graph.NumberOfEdges() << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "Is Edge(1, 1): " << graph.IsEdge(1, 1) << std::endl;
	std::cout << "Is Edge(1, 2): " << graph.IsEdge(1, 2) << std::endl;
	std::cout << "Is Edge(2, 1): " << graph.IsEdge(2, 1) << std::endl << std::endl;


	//------------------------------------------------
	std::string Edge = "Edge(2, 3) ";	//powtórzyæ dla reszty krawêdzi
	auto edge = graph.SelectEdge(2, 3);	
	
	std::cout << Edge << "v0: " << edge->V0()->Number() << std::endl;
	std::cout << Edge << "v1: " << edge->V1()->Number() << std::endl << std::endl;

	std::cout << Edge << "v0 Mate: " << edge->Mate(edge->V0())->Number() << std::endl;
	std::cout << Edge << "v1 Mate: " << edge->Mate(edge->V1())->Number() << std::endl << std::endl;

	edge->weight = (edge->V0()->Number()) + (edge->V1()->Number());
	std::cout << Edge << "weight: " << edge->weight << std::endl << std::endl;
	

	//------------------------------------------------
	std::cout << "Verticies in graph:" << std::endl << std::endl;
	auto& vertIter = graph.VerticesIter();

	while (!vertIter.IsDone()) {
		auto& curr_vert = *vertIter;
		std::cout << "Vertex number: " << curr_vert.Number() << " ";
		std::cout << "weight: " << curr_vert.weight << std::endl;
		++vertIter;
	}

	delete& vertIter;
	std::cout << std::endl << std::endl;


	//------------------------------------------------
	graph.AddEdge(3, 5); std::cout << "AddEdge(3, 5)" << std::endl;
	graph.AddEdge(8, 3); std::cout << "AddEdge(8, 3)" << std::endl;
	graph.AddEdge(5, 2); std::cout << "AddEdge(5, 2)" << std::endl;

	//------------------------------------------------
	std::cout << "\n\nEdges in graph: \n\n";

	auto& edgeIter = graph.EdgesIter();

	while (!edgeIter.IsDone()) {
		auto& edge = *edgeIter;

		std::cout << "Edge(" << edge.V0()->Number() << ", " << edge.V1()->Number() << ")" << std::endl;

		++edgeIter;
	}
	delete& edgeIter;
	std::cout << std::endl << std::endl;


	//------------------------------------------------
	int vertex_nr = 3;
	std::cout << "Edges from vertex " << vertex_nr << ": " << std::endl << std::endl;
	auto& emIter = graph.EmanatingEdgesIter(vertex_nr);

	while (!emIter.IsDone()) {
		auto& edge = *emIter;

		std::cout << "Edge(" << edge.V0()->Number() << ", " << edge.V1()->Number() << ")" << std::endl;

		++emIter;
	}
	delete& emIter;
	std::cout << std::endl << std::endl;


	//------------------------------------------------
	vertex_nr = 2;
	std::cout << "Edges to vertex " << vertex_nr << ": " << std::endl << std::endl;
	auto& incIter = graph.IncidentEdgesIter(vertex_nr);

	while (!incIter.IsDone()) {
		auto& edge = *incIter;

		std::cout << "Edge(" << edge.V0()->Number() << ", " << edge.V1()->Number() << ")" << std::endl;

		++incIter;
	}
	delete& incIter;
	std::cout << std::endl << std::endl;


#elif TEST == 2

	GraphAsMatrix* graph = new GraphAsMatrix(10, false);

	graph->AddEdge(0, 1);	std::cout << "AddEdge(0, 1)" << std::endl;
	graph->AddEdge(1, 2);	std::cout << "AddEdge(1, 2)" << std::endl;
	graph->AddEdge(2, 3);	std::cout << "AddEdge(2, 3)" << std::endl;
	graph->AddEdge(3, 4);	std::cout << "AddEdge(3, 4)" << std::endl;
	graph->AddEdge(3, 7);	std::cout << "AddEdge(3, 7)" << std::endl;
	//graph->AddEdge(4, 5);	std::cout << "AddEdge(4, 5)" << std::endl;
	graph->AddEdge(5, 9);	std::cout << "AddEdge(5, 9)" << std::endl;
	graph->AddEdge(9, 9);	std::cout << "AddEdge(9, 9)" << std::endl;
	graph->AddEdge(6, 8);	std::cout << "AddEdge(6, 8)" << std::endl;
	graph->AddEdge(8, 6);	std::cout << "AddEdge(8, 6)" << std::endl;
	//graph->AddEdge(0, 8);	std::cout << "AddEdge(0, 8)" << std::endl;

		
	std::cout << "\nDFS: " << std::endl;
	graph->DFS(graph->SelectVertex(0));


	std::cout << "\nWritingVisitor: \n";
	WritingVisitor* vis1 = new WritingVisitor;
	graph->DFS_vis(vis1, graph->SelectVertex(0));


	std::cout << "\nCountingVisitor: \n";
	CountingVisitor *vis2 = new CountingVisitor;
	graph->DFS_vis(vis2, graph->SelectVertex(0));
	std::cout << "Number of vertiecies: " << vis2->GetSum() << std::endl;


	delete vis1;
	delete vis2;
	delete graph;

#elif TEST == 3

	GraphAsMatrix* graph = new GraphAsMatrix(10, false);
	std::cout << "Graph is not directed" << std::endl;

	graph->AddEdge(0, 1);	std::cout << "AddEdge(0, 1)" << std::endl;
	graph->AddEdge(1, 2);	std::cout << "AddEdge(1, 2)" << std::endl;
	graph->AddEdge(2, 3);	std::cout << "AddEdge(2, 3)" << std::endl;
	graph->AddEdge(3, 4);	std::cout << "AddEdge(3, 4)" << std::endl;
	graph->AddEdge(3, 7);	std::cout << "AddEdge(3, 7)" << std::endl;
	graph->AddEdge(4, 5);	std::cout << "AddEdge(4, 5)" << std::endl;
	graph->AddEdge(5, 9);	std::cout << "AddEdge(5, 9)" << std::endl;
	graph->AddEdge(9, 9);	std::cout << "AddEdge(9, 9)" << std::endl;
	graph->AddEdge(6, 8);	std::cout << "AddEdge(6, 8)" << std::endl;
	graph->AddEdge(8, 6);	std::cout << "AddEdge(8, 6)" << std::endl;

	std::cout << std::boolalpha;
	std::cout << "\nGraph is connected: " << graph->IsConnected() << std::endl;

	graph->AddEdge(0, 8);	std::cout << "\nAddEdge(0, 8)" << std::endl;

	std::cout << "\nGraph is connected: " << graph->IsConnected() << std::endl;

	
	delete graph;

#elif TEST == 4

	GraphAsMatrix* graph = new GraphAsMatrix(10, true);
	std::cout << "Graph is directed" << std::endl;

	graph->AddEdge(0, 1);	std::cout << "AddEdge(0, 1)" << std::endl;
	graph->AddEdge(1, 2);	std::cout << "AddEdge(1, 2)" << std::endl;
	graph->AddEdge(2, 3);	std::cout << "AddEdge(2, 3)" << std::endl;
	graph->AddEdge(3, 4);	std::cout << "AddEdge(3, 4)" << std::endl;
	graph->AddEdge(3, 7);	std::cout << "AddEdge(3, 7)" << std::endl;
	graph->AddEdge(4, 5);	std::cout << "AddEdge(4, 5)" << std::endl;
	graph->AddEdge(5, 9);	std::cout << "AddEdge(5, 9)" << std::endl;
	graph->AddEdge(9, 9);	std::cout << "AddEdge(9, 9)" << std::endl;
	graph->AddEdge(6, 8);	std::cout << "AddEdge(6, 8)" << std::endl;
	graph->AddEdge(8, 6);	std::cout << "AddEdge(8, 6)" << std::endl;
	graph->AddEdge(0, 8);	std::cout << "AddEdge(0, 8)" << std::endl;
	graph->AddEdge(6, 0);	std::cout << "AddEdge(6, 0)" << std::endl;
	graph->AddEdge(9, 0);	std::cout << "AddEdge(9, 0)" << std::endl;

	std::cout << std::boolalpha;
	std::cout << "\nGraph is strongly connected: " << graph->IsConnected() << std::endl;

	graph->AddEdge(7, 0);	std::cout << "\nAddEdge(7, 0)" << std::endl;

	std::cout << "\nGraph is strongly connected: " << graph->IsConnected() << std::endl;

	
	delete graph;

#endif

}