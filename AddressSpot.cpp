//
// Created by adiel on 26/12/18.
//

#include "AddressSpot.h"

int AddressSpot::getSpot(string address)
{
    return m_spots[address];
}
AddressSpot::AddressSpot()
{
    m_spots.insert({"/instrumentation/airspeed-indicator/indicated-speed-kt",0});
    m_spots.insert({"/instrumentation/altimeter/indicated-altitude-ft",1});
    m_spots.insert({"/instrumentation/altimeter/pressure-alt-ft",2});
    m_spots.insert({"/instrumentation/attitude-indicator/indicated-pitch-deg",3});
    m_spots.insert({"/instrumentation/attitude-indicator/indicated-roll-deg",4});
    m_spots.insert({"/instrumentation/attitude-indicator/internal-pitch-deg",5});
    m_spots.insert({"/instrumentation/attitude-indicator/internal-roll-deg",6});
    m_spots.insert({"/instrumentation/encoder/indicated-altitude-ft",7});
    m_spots.insert({"/instrumentation/encoder/pressure-alt-ft",8});
    m_spots.insert({"/instrumentation/gps/indicated-altitude-ft",9});
    m_spots.insert({"/instrumentation/gps/indicated-ground-speed-kt",10});
    m_spots.insert({"/instrumentation/gps/indicated-vertical-speed",11});
    m_spots.insert({"/instrumentation/heading-indicator/indicated-heading-deg",12});
    m_spots.insert({"/instrumentation/magnetic-compass/indicated-heading-deg",13});
    m_spots.insert({"/instrumentation/slip-skid-ball/indicated-slip-skid",14});
    m_spots.insert({"/instrumentation/turn-indicator/indicated-turn-rate",15});
    m_spots.insert({"/instrumentation/vertical-speed-indicator/indicated-speed-fpm",16});
    m_spots.insert({"/controls/flight/aileron",17});
    m_spots.insert({"/controls/flight/elevator",18});
    m_spots.insert({"/controls/flight/rudder",19});
    m_spots.insert({"/controls/flight/flaps",20});
    m_spots.insert({"/controls/engines/current-engine/throttle",21});
    m_spots.insert({"/engines/engine/rpm",22});
}
