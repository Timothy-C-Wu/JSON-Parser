//
// Created by Timothy Wu on 2019-11-13.
//

#include "JSONTokenizer.hpp"
#include <iostream>

JSONTokenizer::JSONTokenizer(std::string name): inputFileName{name}{
    inputStream.open(inputFileName, std::ios::in);
}

bool JSONTokenizer::charOfInterest(char c) {
    return c == '"' || c == ',' || c == ':' || c == '[' || c == ']' || c == '{' || c == '}' || isdigit(c);
}

JSONToken JSONTokenizer::getToken() {
    if(! inputStream.is_open()){
        std::cout << "JSONTokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }
    JSONToken token;
    char c;
    if(inputStream.eof()){
        token.endOfFile() = true;
        return token;
    }
    while(inputStream.get(c) && ! charOfInterest(c)){
    }
    if(c == '"'){
        std::string attributeName;
        token.isString() = true;
        while (inputStream.peek() != '"' && inputStream.get(c)) {
            attributeName += c;
        }
        token.makeAttributeName(attributeName);
        inputStream.get(c);
        return token;
    }
    else if(isdigit(c)){
        token.isDigit() = true;
        std::string attributeName = "";
        while(inputStream.peek() != ',' &&  inputStream.peek() != '}') {
            attributeName += c;
            inputStream.get(c);
        }
        attributeName+= c;
        token.makeAttributeNum(attributeName);
        return token;
    }
    else if(c == ','){
        token.isComma() = true;
        return token;
    }
    else if(c == ':'){
        token.isColon() = true;
        return token;
    }
    else if (c == '[') {
        token.isOpenBracket() = true;
        return token;
    }
    else if (c == ']'){
        token.isCloseBracket() = true;
        return token;
    }
    else if (c == '{'){
        token.isOpenCurly() = true;
        return token;
    }
    else if (c == '}'){
        token.isCloseCurly() = true;
        return token;
    }
    return token;
}