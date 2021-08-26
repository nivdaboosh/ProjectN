#ifndef UNTITLED_KNN_H
#define UNTITLED_KNN_H

#include <vector>
#include "../Iris.h"

class Knn {
public:
    /**
     * Creates a new Knn.
     */
    Knn();

    /**
     * Finds the type of an Iris.
     * @param iris Iris.
     * @param others std::vector<Iris>.
     * @param k int.
     * @return string.
     */
    string theType(Iris iris, std::vector<Iris> others, int k);

    /**
     * Takes the input from a file with a given path.
     * @param path string.
     * @param isClassified bool. 
     * @param others std::vector<Iris>.
     * @param k int.
     * @return std::vector<Iris>.
     */
    std::vector<Iris> input(string path, bool isClassified, std::vector<Iris> others, int k);

    /**
     * Runs the Knn.
     * @param unclassified string. 
     * @return std::vector<string>.
     */
    std::vector<string> run(string unclassified);
};


#endif //UNTITLED_KNN_H