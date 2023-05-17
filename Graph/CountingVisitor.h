#pragma once

#include <iostream>
#include "Visitor.h"


class CountingVisitor : public Visitor<int> {
private:
	int count = 0;
public:
	void Visit(int &element);
	int GetSum() { return count; }
	bool IsDone() const { return false; }
	void SetAll();

};


void CountingVisitor::Visit(int& element) {
	count++;
}

void CountingVisitor::SetAll() {
	count = 0;
}