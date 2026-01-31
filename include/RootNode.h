#ifndef ROOTNODE_H
#define ROOTNODE_H

#include <string>
#include "DerivedWordList.h"

using namespace std;

class RootNode {
public:
    string root;
    DerivedWordList derivedWords;
    RootNode* left;
    RootNode* right;
    int height;

    RootNode(const string& root)
        : root(root), left(nullptr), right(nullptr), height(1) {}
};

#endif
