#ifndef ROOTTREE_H
#define ROOTTREE_H

#include <string>
#include <iostream>
#include "RootNode.h"

using namespace std;

class RootTree {
private:
    RootNode* root;

    int height(RootNode* node);
    int balanceFactor(RootNode* node);

    RootNode* rotateRight(RootNode* y);
    RootNode* rotateLeft(RootNode* x);

    RootNode* insert(RootNode* node, const string& root);
    RootNode* search(RootNode* node, const string& root) const;
    void display_tree(int level, RootNode* node) const;

public:
    RootTree();

    void insertRoot(const string& root);
    RootNode* searchRoot(const string& root) const;
    void displayRoots() const;
    void insertRootsFromFile(const string& filename);
};

#endif
