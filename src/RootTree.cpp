#include "RootTree.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

RootTree::RootTree() : root(nullptr) {}

int RootTree::height(RootNode* node) {
    return node ? node->height : 0;
}

int RootTree::balanceFactor(RootNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

RootNode* RootTree::rotateRight(RootNode* y) {
    RootNode* x = y->left;
    RootNode* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

RootNode* RootTree::rotateLeft(RootNode* x) {
    RootNode* y = x->right;
    RootNode* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

RootNode* RootTree::insert(RootNode* node, const string& root) {
    if (!node)
        return new RootNode(root);
    if (root < node->root)
        node->left = insert(node->left, root);
    else if (root > node->root)
        node->right = insert(node->right, root);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && root < node->left->root)
        return rotateRight(node);

    if (balance < -1 && root > node->right->root)
        return rotateLeft(node);

    if (balance > 1 && root > node->left->root) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && root < node->right->root) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

RootNode* RootTree::search(RootNode* node, const string& root) const {
    if (!node || node->root == root)
        return node;

    if (root < node->root)
        return search(node->left, root);

    return search(node->right, root);
}

DerivedWord RootTree::dfs(RootNode* node, string word)
{
    if (!node) return DerivedWord();

    DerivedWord found = node->derivedWords.exists(word);
    if (found.word != "")
        return found;

    if (node->left)
    {
        DerivedWord leftResult = dfs(node->left, word);
        if (leftResult.word != "")
            return leftResult;
    }

    if (node->right)
    {
        DerivedWord rightResult = dfs(node->right, word);
        if (rightResult.word != "")
            return rightResult;
    }

    return DerivedWord();
}

DerivedWord RootTree::find_derived_word(RootTree tree, string word)
{
    return dfs(tree.root, word);
}

void RootTree::display_tree(int level, RootNode* node) const {
    if (node != NULL)
    {
        display_tree(level + 1, node->right);
        cout << endl;
        if (node == this->root)
            cout << "Root -> ";
        for (int i = 0; i < level && node != this->root; i++)
            cout << "        ";
        cout << node->root;
        display_tree(level + 1, node->left);
    }
}

void RootTree::insertRoot(const string& root) {
    this->root = insert(this->root, root);
}

RootNode* RootTree::searchRoot(const string& root) const {
    return search(this->root, root);
}

void RootTree::displayRoots() const {
    display_tree(1, this->root);
    cout << endl;
}

void RootTree::insertRootsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string root;
    while (getline(file, root)) {
        if (!root.empty()) {
            insertRoot(root);
        }
    }

    file.close();
}   