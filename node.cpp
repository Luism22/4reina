#include "node.hpp"

using namespace std;

Node::Node()
{
	depth = 1;
	this->board.generateQueens();
	children = vector<Node*>(this->getBoard().getSize() * (this->getBoard().getSize() - 1));
}


Node::Node(Node& other)
{
	this->depth = other.depth + 1;
	this->board = Board(other.board);
	children = vector<Node*>(this->getBoard().getSize() * (this->getBoard().getSize() - 1));
}


bool Node::IsSolved()
{
	return this->board.conflictNumber() == 0; 
}


void Node::expand()
{
	int row = 0, shift = 1;
	for (size_t elem = 0; elem < children.size(); elem++)
	{
		if (shift == this->getBoard().getSize())
		{
			++row;
			shift = 1;
		}
		this->children[elem] = new Node(*this);
		this->children[elem]->board.moveFigure(row, shift);
		++shift;
	}
}
