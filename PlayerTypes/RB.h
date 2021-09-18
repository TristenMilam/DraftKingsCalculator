#ifndef RB_H
#define RB_H

#include <string>

class RB {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    RB() {
        name = "NoName"; espnProj = 0; DKcash = 0;
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}

    RB(std::string name, double espnProj, short DKcash)
    : name(name), espnProj(espnProj), DKcash(DKcash) {}
};

#endif