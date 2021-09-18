#ifndef DE_H
#define DE_H

#include <string>

class DE {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    DE() {
        name = "NoName"; espnProj = 0; DKcash = 0;
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}

    DE(std::string name, double espnProj, short DKcash)
    : name(name), espnProj(espnProj), DKcash(DKcash) {}
};

#endif