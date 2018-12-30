#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H

/****************************************************************
* Class Name: Expression                                        *
* Constructor: Interface (no constructor)                       *
* Class Functionality: Expression interface class containing    *
*   one method: calculate().                                    *
****************************************************************/
class Expression {
public:
    virtual double calculate() = 0;
};
#endif //PROJECT_EXPRESSION_H
