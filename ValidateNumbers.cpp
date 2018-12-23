#include "ValidateNumbers.h"

bool ValidateNumbers::validateNumbers(std::string number)
{
    for (char digit : number) {
        if (digit < 48 || digit > 57) {
            return false;
        }
    }
    return true;
}
bool ValidateNumbers::validateSocket(std::string socket)
{
    for (char digit : socket) {
        if ((digit < 48 || digit > 57) && digit != 46) {
            return false;
        }
    }
    return true;
}