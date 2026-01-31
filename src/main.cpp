#include <iostream>
#include <windows.h>
#include "Pattern.h"
using namespace std;

int main() {
    Pattern p;
    wstring pattern = L"مفعول";
    wcout<<pattern<<endl;
    wcout<<p.TransformationRule(pattern);
    return 0;
}
