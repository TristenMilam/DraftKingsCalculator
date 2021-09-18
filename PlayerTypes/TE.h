#ifndef TE_H
#define TE_H

#include <string>

class TE {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    TE() {
        name = "NoName"; espnProj = 0; DKcash = 0;
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}

    TE(std::string name, double espnProj, short DKcash)
    : name(name), espnProj(espnProj), DKcash(DKcash) {}
};

#endif