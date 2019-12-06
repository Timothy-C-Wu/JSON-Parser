//
// Created by student on 2019-11-15.
//

#ifndef PROJECT02_ENTITYINSTANCE_H
#define PROJECT02_ENTITYINSTANCE_H

#include "pair.h"
#include <vector>
#include <string>

class EntityInstance {
public:
    void addAttribute(Pair &pair);
    int numAttributes();
    std::vector<std::string> &attributeNames();
    void print();   // prints this object
    double getFirstGpa();
    double getSecondGpa();
    std::string getTerm();
    std::string getId();

private:
    std::vector<Pair> entityAttributes;
};

#endif //PROJECT02_ENTITYINSTANCE_H
