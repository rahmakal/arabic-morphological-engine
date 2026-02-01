#include <iostream>

#include "HashTable.h"
#include "Pattern.h"
using namespace std;

int main() {
    Pattern p;
    string pattern = "مفعول";
    HashTable mp;
    mp.insert(pattern, p);
    return 0;
}
