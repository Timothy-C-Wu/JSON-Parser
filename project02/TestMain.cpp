//
// Created by Timothy Wu on 2019-11-15.
//

#include "JSONTokenizer.hpp"
#include "JSONToken.hpp"
#include "JSONParser.hpp"
#include "pair.h"
#include <iostream>
#include <fstream>

//using namespace std;

int main(int argc, char *argv[]) {
    if( argc != 2){
        std::cout << "usage: " << argv[0] << "nameOfAnInputFile" << std::endl;
    }
    std::ifstream inputStream;
    std::ifstream inputStream2;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    inputStream2.open(argv[2], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    if (!inputStream2.is_open()) {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        exit(2);
    }
    inputStream.close();
    inputStream2.close();
    JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.
    JSONTokenizer jsonTokenizer2(argv[2]); // The Tokenizer opens and reads from the input file.
    JSONParser parse(jsonTokenizer);
    JSONParser parse2(jsonTokenizer2);
    Entity ent = parse.parseJSONEntity();
    Entity ent2 = parse2.parseJSONEntity();
    Entity final = ent2.intersection(ent);

    final.print();
    std::vector<std::vector<int>> matrix = final.makeMatrix();
    final.printMatrix(matrix);
    return 0;
}