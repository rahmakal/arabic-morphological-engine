#include <algorithm>
#include "Pattern.h"
#include <string>
#include <iostream>
using namespace std;
string Pattern::TransformationRule(string key)
{
    wstring rule = L"";
    for (wchar_t c:key)
    {
        wcout<<c<<endl;
        if (c == L'ف' || c == L'ع' || c == L'ل')
        {
            rule+='*';
        }else
        {
            rule+=c;
        }
    }
    reverse(rule.begin(), rule.end());
    return rule;
}
