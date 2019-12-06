//
// Created by student on 2019-11-13.
//

#ifndef LAB01_2_JSONPARSER_H
#define LAB01_2_JSONPARSER_H

#include "JSONToken.hpp"
#include "JSONTokenizer.hpp"
#include "pair.h"
#include "EntityInstance.hpp"
#include "Entity.hpp"
#include <iostream>
#include <iomanip>

class JSONParser {
public:
    JSONParser(JSONTokenizer &tokenizer);

    Pair parseAPair();
    EntityInstance parseJSONObject();
    Entity parseJSONEntity();

private:
    JSONTokenizer &tokenizer;
};


#endif //LAB01_2_JSONPARSER_H
