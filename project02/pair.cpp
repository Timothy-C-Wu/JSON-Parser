//
// Created by Timothy Wu on 2019-11-13.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "pair.h"

using namespace std;

Pair::Pair(std::string attributeName, double attributeNum): _attributeName{attributeName},
                                                            _attributeStringValue{""},
                                                            _attributeNumberValue{attributeNum},
                                                            _isNumber{true} {}



Pair::Pair(std::string attributeName, std::string attributeValue): _attributeName{attributeName},
                                                                   _attributeStringValue{attributeValue},
                                                                   _attributeNumberValue{-1},
                                                                   _isNumber{false} {}


void Pair::print() {
    if (isDouble())
        cout << '\"' << attributeName() << "\": " << _attributeNumberValue << "," << endl;
    else
        cout << '\"' << attributeName() << "\": " << _attributeStringValue << "," << endl;
}

bool Pair::isDouble() { return _isNumber; }

double Pair::numberValue() { return _attributeNumberValue; }

string Pair::stringValue() {return _attributeStringValue;}

string Pair::attributeName() {return _attributeName;}



