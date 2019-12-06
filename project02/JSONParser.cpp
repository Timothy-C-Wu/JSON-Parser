//
// Created by student on 2019-11-13.
//

#include "JSONParser.hpp"

JSONParser::JSONParser(JSONTokenizer &tokenizer): tokenizer{tokenizer}{};


EntityInstance JSONParser::parseJSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenCurly() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseCurly() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}


Pair JSONParser::parseAPair() {
    JSONToken tokenKey = tokenizer.getToken();
    if (!tokenKey.isString()) {
        std::cout << "Error: JSONParser::parseAPair: Expected a string, but found" << std::endl;
        tokenKey.print();
        std::cout << "terminating..." << std::endl;
        exit(1);
    }
    JSONToken tokenColon = tokenizer.getToken();
    if (!tokenColon.isColon()) {
        std::cout << "Error: JSONParser::parseAPair: Expected a colon, but found" << std::endl;
        tokenKey.print();
        std::cout << "terminating..." << std::endl;
        exit(1);
    }
    JSONToken tokenValue = tokenizer.getToken();
    if (tokenValue.isString()) {
        Pair pair (tokenKey.attributeName(), tokenValue.attributeName());
        return pair;
    }
    else if(tokenValue.isDigit()){
        Pair pair(tokenKey.attributeName(),tokenValue.attributeNum());
        return pair;
    }
    else
        std::cout << "Error: JSONParser::parseAPair: Expected a string or double, but found" << std::endl;
        tokenKey.print();
        std::cout << "terminating..." << std::endl;
        exit(1);
    }

Entity JSONParser::parseJSONEntity() {
    //add pair to entity attributes
    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    Entity ent;
    do {
        instance = parseJSONObject();
        ent.addObject(instance);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return ent;

}