#ifndef UNTITLED_KNN_H
#define UNTITLED_KNN_H

#include <vector>
#include "../Iris.h"

class Knn {
public:
    Knn();
    string theType(Iris iris, std::vector<Iris> others, int k);
    std::vector<Iris> input(string path, bool isClassified, std::vector<Iris> others, int k);
    std::vector<string> Knn::run(string unclassified)
};


#endif //UNTITLED_KNN_H
