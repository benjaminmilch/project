#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H


#include "Expression.h"
#include <string>

using namespace std;

class Number : public Expression{
    double m_value;
public:
    Number(string val);
    double calculate() override;
};


#endif //PROJECT_NUMBER_H