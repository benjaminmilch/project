#include "ValidateNumbers.h"

bool ValidateNumbers::validateNumbers(std::string number)
{
    for (char digit : number) {
        if (digit < 48 || digit > 57) { // 48-57 values of 0-9 on the ASCII table
            return false;
        }
    }
    return true;
}
bool ValidateNumbers::validateIP(std::string IP)
{
    int counter = 0; // counts the digits between "."
    int period = 0; // counts the "." in the IP address
    for (char digit : IP) {
        counter++;
        if (counter > 4) { // number is larger than 3 digits long
            return false;
        } else if (counter == 1 && digit == 46) { // no digit between "."
            return false;
        } else if ((digit < 48 || digit > 57) && digit != 46) { // invalid digit input
            return false;
        }
        if (digit == 46) { // digit is a "."
            counter = 0;
            period++;
        }
    }
    return period == 3; // final check that the IP had the required 3 "."
}