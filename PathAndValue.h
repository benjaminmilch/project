//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_PATHANDVALUE_H
#define PROJECT_PATHANDVALUE_H

#include <string>

using namespace std;

class PathAndValue {
    string m_path;
    double m_value;
public:
    PathAndValue(string path);
    void updateValue(double value);
    string getPath();
};


#endif //PROJECT_PATHANDVALUE_H
