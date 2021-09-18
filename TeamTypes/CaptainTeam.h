#ifndef CAPTAINTEAM_H
#define CAPTAINTEAM_H

#include "../PlayerTypes/GenericPlayer.h"
#include "../PlayerTypes/Captain.h"
#include <iostream>

struct CaptainTeam {
    Captain cpt;
    GenericPlayer p1, p2, p3, p4, p5;
    double projScore;
    int totalPrice;

    CaptainTeam(Captain& cpt, GenericPlayer p1, GenericPlayer p2,
            GenericPlayer p3, GenericPlayer p4, GenericPlayer p5) {
        this->cpt = cpt;
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        this->p5 = p5;
        projScore = cpt.getProj() + p1.getProj() + p2.getProj() +
                    p3.getProj() + p4.getProj() + p5.getProj();
        totalPrice = cpt.getPrice() + p1.getPrice() + p2.getPrice() +
                    p3.getPrice() + p4.getPrice() + p5.getPrice();
    }
};

std::ostream& operator<<(std::ostream& os, CaptainTeam& team) {
    os << "Captain: " << team.cpt.getName() << std::endl;
    os << team.p1.getName() << " " << team.p2.getName() << " "
       << team.p3.getName() << std::endl;
    os << team.p4.getName() << " " << team.p5.getName()
       << "      Projected: " << team.projScore;
    return os;
}

bool operator<(const CaptainTeam& lhs, const CaptainTeam& rhs) {
    if (lhs.projScore < rhs.projScore) { return true; }
    return false;
}

bool operator==(const CaptainTeam& lhs, const CaptainTeam& rhs) {
    int equalCounter = 0;
    if (lhs.cpt.getName() == rhs.cpt.getName()) equalCounter += 1;
    if (lhs.p1.getName() == rhs.p1.getName() ||
        lhs.p1.getName() == rhs.p2.getName() ||
        lhs.p1.getName() == rhs.p3.getName() ||
        lhs.p1.getName() == rhs.p4.getName() ||
        lhs.p1.getName() == rhs.p5.getName()) equalCounter += 1;
    if (lhs.p2.getName() == rhs.p1.getName() ||
        lhs.p2.getName() == rhs.p2.getName() ||
        lhs.p2.getName() == rhs.p3.getName() ||
        lhs.p2.getName() == rhs.p4.getName() ||
        lhs.p2.getName() == rhs.p5.getName()) equalCounter += 1;
    if (lhs.p3.getName() == rhs.p1.getName() ||
        lhs.p3.getName() == rhs.p2.getName() ||
        lhs.p3.getName() == rhs.p3.getName() ||
        lhs.p3.getName() == rhs.p4.getName() ||
        lhs.p3.getName() == rhs.p5.getName()) equalCounter += 1;
    if (lhs.p4.getName() == rhs.p1.getName() ||
        lhs.p4.getName() == rhs.p2.getName() ||
        lhs.p4.getName() == rhs.p3.getName() ||
        lhs.p4.getName() == rhs.p4.getName() ||
        lhs.p4.getName() == rhs.p5.getName()) equalCounter += 1;
    if (lhs.p5.getName() == rhs.p1.getName() ||
        lhs.p5.getName() == rhs.p2.getName() ||
        lhs.p5.getName() == rhs.p3.getName() ||
        lhs.p5.getName() == rhs.p4.getName() ||
        lhs.p5.getName() == rhs.p5.getName()) equalCounter += 1;
    if (equalCounter > 3) return true;
    return false;
}

#endif