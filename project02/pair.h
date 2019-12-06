//
// Created by student on 2019-11-13.
//

#ifndef LAB01_2_PAIR_H
#define LAB01_2_PAIR_H

#include <string>

class Pair { // represents a single attribute and its value:

public:
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, double attributeNum);
    bool isDouble();  // is the datatype of the value of this attribute a double?
    double numberValue();
    std::string stringValue();
    std::string attributeName();
    void print();
private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber;
};

#endif //LAB01_2_PAIR_H
