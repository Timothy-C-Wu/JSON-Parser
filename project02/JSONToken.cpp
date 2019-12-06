//
// Created by Timothy Wu on 2019-11-13.
//

#include <iostream>
#include <iomanip>
#include "JSONToken.hpp"

using namespace std;

JSONToken::JSONToken(): _isString{false},
                        _isDigit{false},
                        _isComma{false},
                        _isColon{false},
                        _isOpenBracket{false},
                        _isCloseBracket{false},
                        _isOpenCurly{false},
                        _isCloseCurly{false},
                        _attributeNum(0.0),
                        _eof{false},
                        _attributeName{""}{};


bool &JSONToken::isString() { return _isString;}

bool &JSONToken::isDigit() {return _isDigit;}

bool &JSONToken::isComma() {return _isComma;}

bool &JSONToken::isColon() {return _isColon;}

bool &JSONToken::isOpenBracket() {return _isOpenBracket;}

bool &JSONToken::isCloseBracket() { return _isCloseBracket;}

bool &JSONToken::isOpenCurly() { return _isOpenCurly;}

bool &JSONToken::isCloseCurly() { return _isCloseCurly;}

bool &JSONToken::endOfFile() { return _eof;}

std::string JSONToken::attributeName(){ return _attributeName;}

double JSONToken::attributeNum() { return _attributeNum;}

void JSONToken::makeAttributeNum(std::string num){
    _attributeNum = stod(num);
}

void JSONToken::makeAttributeName (std::string name) {
    _attributeName = name;
}

void JSONToken::print() {
    if(isString())
        std::cout << attributeName() << std::endl;
    else if(isDigit())
        std::cout << attributeNum() << std::endl;
    else if(isComma())
        std::cout << ',' <<std::endl;
    else if(isColon())
        std::cout << ':' << std::endl;
    else if(isOpenBracket())
        std::cout << '[' << std::endl;
    else if(isCloseBracket())
        std::cout << ']' << std::endl;
    else if(isOpenCurly())
        std::cout << '{' << std::endl;
    else if(isCloseCurly())
        std::cout << '}' << std::endl;
}