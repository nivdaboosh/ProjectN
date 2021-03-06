#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

#include "../Iris.h"
#include "Knn.h"

/**
 * Creates a new Knn.
 */
Knn::Knn() = default;

/**
 *
 * @param iris - the iris to classify.
 * @param others - classified irises.
 * @param k - the amount of the nearest irises to classify by.
 * @return the type of unclassified iris.
 */
string Knn::theType(Iris iris, std::vector<Iris> others, int k) {
    int numVersicolor = 0;
    int numVirginica = 0;
    int numSetosa = 0;
    std::vector<double> distances;
    std::map<double, Iris> map;
    for (int i = 0; i < others.size(); i++) {
        distances.push_back(iris.getDistance(others[i]));
        map.insert(std::pair<double, Iris>(distances[i], others[i]));
    }
    std::sort(distances.begin(), distances.end());
    for (int i = 0; i < k; ++i) {
        auto iterator = map.find(distances[i]);
        if (iterator->second.getType() == "Iris-virginica") {
            numVirginica++;
        }
        if (map.find(distances[i])->second.getType() == "Iris-versicolor") {
            numVersicolor++;
        }
        if (map.find(distances[i])->second.getType() == "Iris-setosa") {
            numSetosa++;
        }
    }
    if (numVirginica > numVersicolor && numVirginica > numSetosa) {
        return "Iris-virginica";
    } else if (numVersicolor > numSetosa) {
        return "Iris-versicolor";
    } else {
        return "Iris-setosa";
    }
}

/**
 * input function.
 * @param path - the path to files classified or unclassified.
 * @param isClassified - bool param - present classify or not.
 * @param others - classified irises
 * @param k - the amount of the nearest irises to classify by.
 * @return irises vector.
 */
std::vector<Iris> Knn::input(string path, bool isClassified, std::vector<Iris> others, int k) {
    ifstream file(path);
    std::vector<Iris> irises;
    string myText;
    while (std::getline(file, myText)) {
        double x = std::stod(std::strtok(const_cast<char *>(myText.c_str()), ","));
        double y = std::stod(std::strtok(nullptr, ","));
        double z = std::stod(std::strtok(nullptr, ","));
        double w = std::stod(std::strtok(nullptr, ","));
        string isType;
        if (isClassified) {
            isType = std::strtok(nullptr, ",");
        }
        string type;
        if (isClassified) {
            type = isType;
        } else {
            Iris helper = Iris(x, y, z, w, "");
            type = theType(helper, others, k);
        }
        irises.emplace_back(x, y, z, w, type);
    }
    file.close();
    return irises;
}

/**
 * main - starts the program.
 * @return 0.
 */
std::vector<string> Knn::run(string unclassified) {
    int k = 5;
    string pathC = "classified.csv";
    string pathU = std::move(unclassified);
    std::vector<Iris> nullVector;
    std::vector<Iris> classified = input(std::string(pathC), true, nullVector, k);
    std::vector<Iris> irises = input(std::string(pathU), false, classified, k);
    std::vector<string> output;
    for (int i = 0; i < irises.size(); ++i) {
        output.push_back(irises[i].getType());
    }
    return output;
}