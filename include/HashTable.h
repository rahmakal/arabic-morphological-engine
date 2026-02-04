#ifndef ARABIC_MORPHOLOGICAL_ENGINE_HASHTABLE_H
#define ARABIC_MORPHOLOGICAL_ENGINE_HASHTABLE_H
#include <string>
#include <vector>
#include <Pattern.h>
using namespace std;
class HashTable
{
public:
    HashTable();
    void insert(string key, Pattern value);
    Pattern search(string key);
    void modify(string key, string new_key);
    void delete_key(string key);
    void show_hash_table();
    void insertPatternsFromFile(const string& filename);
private:
    vector<Pattern> values;
    int find_index(string key);

};

#endif //ARABIC_MORPHOLOGICAL_ENGINE_HASHTABLE_H