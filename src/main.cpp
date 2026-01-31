#include <iostream>
#include "Pattern.h"
using namespace std;

int main() {
    Pattern p;
    string pattern = "مفعول";
    cout<<pattern<<endl;
    cout<<p.TransformationRule(pattern);
    return 0;
}
