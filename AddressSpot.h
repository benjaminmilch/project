//
// Created by adiel on 26/12/18.
//

#ifndef PROJECT_ADDRESSSPOT_H
#define PROJECT_ADDRESSSPOT_H

#include <map>
#include <string>

/****************************************************************
* Class Name: AddressSpot                                       *
* Constructor: Default constructor                              *
* Class Functionality: This class creates a map with all the    *
*   addresses in the XML file and their index.                  *
****************************************************************/
using namespace std;

class AddressSpot {
    map<string, int> m_spots; // member
public:
    AddressSpot(); // constructor

    int getSpot(string address); // retrieve the index of a specific address (key)

};


#endif //PROJECT_ADDRESSSPOT_H
