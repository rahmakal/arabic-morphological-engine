#include <iostream>
#include "RootTree.h"

using namespace std;

int main() {
    RootTree tree;
    tree.insertRootsFromFile("../data/roots.txt");
    tree.displayRoots();
    return 0;
}
