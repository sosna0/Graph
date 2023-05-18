#pragma once

#include <iostream>
#include "Visitor.h"


class WritingVisitor : public Visitor<int> {
public:
	void Visit(int& element);
	bool IsDone() const { return false; }
	void SetAll(){}
};

void WritingVisitor::Visit(int& element) {
	std::cout << "Vertex: " << element << std::endl;
}
