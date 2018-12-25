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
bool ValidateNumbers::validateIP(std::string IP)
{
    for (char digit : IP) {
        if ((digit < 48 || digit > 57) && digit != 46) {
            return false;
        }
    }
    return true;
}