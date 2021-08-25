#include "Iris.h"
#include <iostream>
#include <string>
#include <cmath>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using namespace std;


Iris::Iris(double x, double y, double z, double w, string type) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
    this->type = std::move(type);
}

double Iris::getDistance(Iris other) {
    double powX = pow(this->x - other.x, 2);
    double powY = pow(this->y - other.y, 2);
    double powZ = pow(this->z - other.z, 2);
    double powW = pow(this->w - other.w, 2);
    return sqrt(powX + powY + powZ + powW);
}

string Iris::getType() {
    return this->type;
}