#ifndef QB_H
#define QB_H

#include <string>

class QB {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    QB() {
        name = "NoName"; espnProj = 0; DKcash = 0;
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}

    QB(std::string name, double espnProj, short DKcash)
    : name(name), espnProj(espnProj), DKcash(DKcash) {}
};

#endif