//
// Created by Timothy Wu on 11/16/2019.
//

#include "Entity.hpp"


void Entity::addObject(EntityInstance &instance) {
    instances.push_back(instance);
}
void Entity::print(){
    for (int i = 0; i < instances.size(); i++)
      instances[i].print();
}


Entity Entity::intersection(Entity first) {
    Entity final;

    for(EntityInstance first: first.instances){
        std::string firstId = first.getId();
        for (EntityInstance second: instances){
            std::string secondId = second.getId();
            if (firstId != secondId)
                continue;
            double firstGpa = first.getFirstGpa();
            double secondGpa = second.getFirstGpa();
            EntityInstance finalIns;

            Pair idPair("id", firstId);
            Pair termOneGpa("gpa", firstGpa);
            Pair termTwoGpa("secondGpa", secondGpa);

            finalIns.addAttribute(idPair);
            finalIns.addAttribute(termOneGpa);
            finalIns.addAttribute(termTwoGpa);

            final.addObject(finalIns);

        }
    }
    return final;

}

int Entity::getIndex(double gpa) {
    if (gpa >= 0.0 && gpa <= 1.67)
        return 7;
    if (gpa > 1.67 && gpa <= 2.0)
        return 6;
    if (gpa > 2.0 && gpa <= 2.3)
        return 5;
    if (gpa > 2.3 && gpa <= 2.67)
        return 4;
    if (gpa > 2.67 && gpa <= 3.0)
        return 3;
    if (gpa > 3.0 && gpa <= 3.3)
        return 2;
    if (gpa > 3.3 && gpa <= 3.67)
        return 1;
    if (gpa > 3.67 && gpa <= 4.0)
        return 0;
    else
        return -1;
}
std::vector<std::vector<int>> Entity::makeMatrix(){
    std::vector<std::vector<int>> matrixOfGpa(8, std::vector<int> (8,0));
    for (EntityInstance l: instances){
        double oldGpa = l.getFirstGpa();
        double newGpa = l.getSecondGpa();
        int idx1 = getIndex(oldGpa);
        int idx2 = getIndex(newGpa);
        matrixOfGpa[idx1][idx2]++;
    }
    return matrixOfGpa;
}

void Entity::printMatrix(std::vector<std::vector<int>> matrix) {
    std::ofstream ofs ("result.json", std::ofstream::out);
    for(int i = 0; i < 8; i++) {
        if(i == 0)
            ofs << "[" << std::endl;
        for (int x = 0; x < 8; x++) {
            if (x == 0)
                ofs << "[";
            if(x == 7)
                ofs << matrix[i][x];
            else if(x <7)
                ofs << matrix[i][x] <<",";
            if (i == 7 && x== 7)
                ofs << "]" << std::endl;
            else if(i !=7 && x== 7)
                ofs << "]," << std::endl;
        }
        if(i == 7)
            ofs << "]";
    }
    ofs.close();
}

//bands 0.0 -1.67, 1.67-2.0, 2.0-2.3, 2.3-2.67, 2.67-3.0, 3.0-3.3, 3.3-3.67, 3.67-4.0