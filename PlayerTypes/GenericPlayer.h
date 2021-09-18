#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <string>

class GenericPlayer {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    GenericPlayer() {
        name = "NoName"; espnProj = 0; DKcash = 0;
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}

    GenericPlayer(std::string name, double espnProj, short DKcash)
    : name(name), espnProj(espnProj), DKcash(DKcash) {}
};

#endif