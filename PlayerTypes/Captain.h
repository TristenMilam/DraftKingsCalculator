//Captain class

#ifndef CAPTAIN_H
#define CAPTAIN_H

#include <string>

class Captain {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    Captain() {
        name = "NoName"; espnProj = 0; DKcash = 0;
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}

    Captain(std::string name, double espnProj, short DKcash)
    : name(name), espnProj(1.5 * espnProj), DKcash(1.5 * DKcash) {}
};

#endif