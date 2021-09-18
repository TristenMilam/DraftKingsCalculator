#ifndef FL_H
#define FL_H

#include <string>

class FL {
    public:
    std::string name;
    double espnProj;
    short DKcash;
    std::string type;
    FL() {
        name = "NoName"; espnProj = 0; DKcash = 0; type = "NA";
    }
    std::string getName() const { return name;}
    double getProj() const { return espnProj;}
    short getPrice() const { return DKcash;}
    std::string getType() const { return type; }
    FL(std::string name, double espnProj, short DKcash, std::string type)
    : name(name), espnProj(espnProj), DKcash(DKcash), type(type) {}
};

#endif