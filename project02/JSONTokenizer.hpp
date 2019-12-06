//
// Created by student on 2019-11-13.
//

#ifndef PROJECT2_JSONTOKENIZER_HPP
#define PROJECT2_JSONTOKENIZER_HPP

#include <string>
#include <fstream>
#include "JSONToken.hpp"

class JSONTokenizer{

public:
    JSONTokenizer(std::string name);
    JSONToken getToken();

private:
    std::string inputFileName;
    std::ifstream inputStream;

    bool charOfInterest(char c);
};

#endif //PROJECT2_JSONTOKENIZER_HPP
