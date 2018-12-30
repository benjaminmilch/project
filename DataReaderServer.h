//
// Created by adiel on 25/12/18.
//

#ifndef PROJECT_DATAREADERSERVER_H
#define PROJECT_DATAREADERSERVER_H

#include "GlobalData.h"

/****************************************************************
* Class Name: DataReaderServer                                  *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class runs the server socket in the *
*   background, updating based on the inputted frequency.       *
****************************************************************/
class DataReaderServer {
    GlobalData* m_globalData; // member
public:
    explicit DataReaderServer(GlobalData *gd); // constructor

    void runServer (int port, int freq); // runs the server socket in the background (by thread)
};


#endif //PROJECT_DATAREADERSERVER_H
