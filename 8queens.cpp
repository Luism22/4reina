#include "tree.hpp"

using namespace std;

int main()
{
    Tree tree;
    cout << "Estado inicial: " << endl;
    tree.getRoot()->getBoard().print();
    cout << "\n\nEstado final: " << endl;
    tree.AStar();
    return 0;
}