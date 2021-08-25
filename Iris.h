#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

#ifndef UNTITLED_IRIS_H
#define UNTITLED_IRIS_H

/**
 * class Iris.
 * double x,y,w,z
 */
class Iris {
private:
    double x;
    double y;
    double z;
    double w;
    string type;
public:
    /**
     * Constructor. Creates a new Iris.
     * @param x -double.
     * @param y -double.
     * @param z -double.
     * @param w -double.
     * @param type -string.
     */
    Iris(double x, double y, double z, double w, string type);

    /**
     * Calculates the distance from a Iris to an other Iris.
     * @param other - the iris to get the distance from.
     * @return -double distance.
     */
    double getDistance(Iris other);

    /**
     * @return Returns the type of the Iris.
     */
    string getType();

};

#endif //UNTITLED_IRIS_H};