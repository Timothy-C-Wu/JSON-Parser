//
// Created by student on 2019-11-13.
//

#ifndef PROJECT2_JSONTOKEN_HPP
#define PROJECT2_JSONTOKEN_HPP

#include <string>

class JSONToken {
public:
    JSONToken();
    bool &isString();
    bool &isDigit();
    bool &isComma();
    bool &isColon();
    bool &isOpenBracket();
    bool &isCloseBracket();
    bool &isOpenCurly();
    bool &isCloseCurly();
    bool &endOfFile();

    std::string attributeName();
    double attributeNum();

    void makeAttributeNum(std::string num);
    void makeAttributeName(std::string name);
    void print();


private:
    bool _isString, _isDigit, _isComma, _isColon, _isOpenBracket,
    _isCloseBracket, _isOpenCurly, _isCloseCurly, _eof;

    std::string _attributeName;
    double _attributeNum;
};

#endif //PROJECT2_JSONTOKEN_HPP
