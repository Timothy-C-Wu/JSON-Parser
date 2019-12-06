//
// Created by timmo on 11/16/2019.
//

#ifndef PROJECT02_ENTITY_HPP
#define PROJECT02_ENTITY_HPP

#include "EntityInstance.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <ostream>
#include <fstream>

class Entity {
public:
    void addObject(EntityInstance &instance);
    Entity intersection(Entity first);
    void print();    // prints all instances of this Entity.
    int getIndex(double gpa);
    void printMatrix(std::vector<std::vector<int>>);
    std::vector<std::vector<int>> makeMatrix();


private:
    std::vector<EntityInstance> instances;

};

#endif //PROJECT02_ENTITY_HPP
