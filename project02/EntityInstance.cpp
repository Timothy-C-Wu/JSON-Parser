//
// Created by Timothy Wu on 2019-11-15.
//

#include "EntityInstance.hpp"

using namespace std;

void EntityInstance::addAttribute(Pair &pair) {
    entityAttributes.push_back(pair);
}

int EntityInstance::numAttributes() {
    return entityAttributes.size();
}

double EntityInstance::getFirstGpa() {
    for (int i = 0; i < entityAttributes.size(); i++)
        if(entityAttributes[i].attributeName() == "gpa")
            return entityAttributes[i].numberValue();
}

double EntityInstance::getSecondGpa() {
    for (int i = 0; i < entityAttributes.size(); i++)
        if(entityAttributes[i].attributeName() == "secondGpa")
            return entityAttributes[i].numberValue();
}

std::string EntityInstance::getId() {
    for (int i = 0; i < entityAttributes.size(); i++)
        if(entityAttributes[i].attributeName() == "id")
            return entityAttributes[i].stringValue();
}

std::string EntityInstance::getTerm() {
    for (int i = 0; i < entityAttributes.size(); i++)
        if(entityAttributes[i].attributeName() == "term")
            return entityAttributes[i].stringValue();
}

void EntityInstance::print() {
    for (int i = 0; i < numAttributes(); i++)
        entityAttributes[i].print();
}

std::vector<std::string> &EntityInstance::attributeNames() {
    std::vector<std::string> instanceNames;
    for(int i = 0; i <= entityAttributes.size(); i++)
        instanceNames.push_back(entityAttributes[i].attributeName());
    return instanceNames;
}
