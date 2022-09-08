#include "tree.hpp"
#include <queue>
#include <algorithm>

using namespace std;

Tree::Tree()
{
	root = new Node();	
	memory_states = total_states = 1;
	iter = 0;
}


Node* Tree::getRoot()
{
	return this->root;
}


void Tree::IDS()
{
	int limit = 1;
	while (!(LDFS(root, limit)))
	{
		++limit; 
		memory_states = 1;
	}
}


bool Tree::LDFS(Node* node, int& limit)
{
	node->getBoard().print();
	cout << "Depth: " << node->getDepth() << endl;
	cout << "Limit: " << limit << endl;
	cout << "Conflicts: " << node->getBoard().conflictNumber() << endl << endl << endl << endl;

	++iter;
	if (node->IsSolved())
	{
		node->getBoard().print();
		cout << "Depth: " << node->getDepth() << endl;
		cout << "Limit: " << limit << endl;
		return true;
	}
	if (node->getDepth() < limit)
	{
		node->expand();
		memory_states += 56;
		total_states += 56;
		for (size_t elem = 0; elem < node->getChildren().size(); elem++)
		{
			if (LDFS(node->getChildren()[elem], limit))
			{
				return true;
			}}}
	return false;
}
void Tree::AStar()
{	
	priority_queue <Node*, vector<Node*>, mycompare> opened;
	vector<Board> closed;
	opened.push(root);
	int iter = 0, all_states = 0, memory_states = 0;
	while (!opened.empty())
	{
		if (opened.top()->IsSolved())
		{
			opened.top()->getBoard().print();
			break;
		}

		closed.push_back(opened.top()->getBoard());
		opened.top()->expand();
		vector<Node*> temp = opened.top()->getChildren();
		opened.pop();
		for (size_t i = 0; i < temp.size(); i++)
		{
			for (size_t j = 0; j < closed.size(); j++)
			{
				if (temp[i]->getBoard() == closed[j])
				{
					continue;
          }}
			opened.push(temp[i]);
		}
		++iter;
	}}
