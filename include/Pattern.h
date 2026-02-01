#ifndef ARABIC_MORPHOLOGICAL_ENGINE_PATTERN_H
#define ARABIC_MORPHOLOGICAL_ENGINE_PATTERN_H
#include <string>
using namespace std;
class Pattern
{
public:
    Pattern();
    void TransformationRule(string key);
    string transformed_word();
private:
    string transformed_word_;
};


#endif //ARABIC_MORPHOLOGICAL_ENGINE_PATTERN_H