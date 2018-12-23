#include "Number.h"

Number::Number(string val) {
    m_value = stod(val);
}
double Number::calculate() {
    return m_value;
}