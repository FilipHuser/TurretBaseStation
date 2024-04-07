#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"

class Director {
public:
//CONSTRUCTOR
    Director() : builder(nullptr) {};

//METHODS
    void buildMinimalBaseStation();

//SETTERS
    void setBuilder(Builder* builder) { this->builder = builder; }
    
private:
    Builder* builder;
};

#endif //DIRECTOR_H