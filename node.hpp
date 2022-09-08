#pragma once
#include "Board.hpp"

using namespace std;

class Node {
private:
	int depth;
	Board board;
	vector<Node*> children;

public:
	Node();
	Node(Node& other);
	bool IsSolved();
	void expand();
    int getDepth() const { return depth; }
    Board getBoard() const { return board; }
    vector<Node*> getChildren() const { return this->children; }

};


struct mycompare {
	bool operator()(const Node* first, const Node* second) {
		if (first->getBoard().conflictNumber() != second->getBoard().conflictNumber())
		{
			return first->getBoard().conflictNumber() > second->getBoard().conflictNumber();
		}
		return first->getDepth() > second->getDepth();
	};
};
