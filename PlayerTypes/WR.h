#ifndef WR_H
#define WR_H

#include <string>

class WR {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    WR() {
        name = "NoName"; espnProj = 0; DKcash = 0; 
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}

    WR(std::string name, double espnProj, short DKcash)
    : name(name), espnProj(espnProj), DKcash(DKcash) {}
};

#endif