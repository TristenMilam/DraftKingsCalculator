#ifndef STANDARDTEAM_H
#define STANDARDTEAM_H

#include "../PlayerTypes/QB.h"
#include "../PlayerTypes/RB.h"
#include "../PlayerTypes/WR.h"
#include "../PlayerTypes/TE.h"
#include "../PlayerTypes/DE.h"
#include "../PlayerTypes/FL.h"
#include <iostream>

struct StandardTeam {
    QB qb;
    RB rb1, rb2;
    WR wr1, wr2, wr3;
    TE te;
    DE de;
    FL fl;
    double projScore;
    int totalPrice;

    StandardTeam(QB& qb, RB& rb1, RB& rb2, WR& wr1, WR& wr2, WR& wr3, TE& te, DE& de, FL& fl) {
        this->qb = qb;
        this->rb1 = rb1; this->rb2 = rb2;
        this->wr1 = wr1; this->wr2 = wr2; this->wr3 = wr3;
        this->te = te;
        this->de = de;
        this->fl = fl;
        projScore = qb.getProj() + rb1.getProj() + rb2.getProj() + wr1.getProj() + wr2.getProj()
        + wr3.getProj() + te.getProj() + de.getProj() + fl.getProj();
        totalPrice = qb.getPrice() + rb1.getPrice() + rb2.getPrice() + wr1.getPrice() + wr2.getPrice()
        + wr3.getPrice() + te.getPrice() + de.getPrice() + fl.getPrice();
    }
};

std::ostream& operator<<(std::ostream& os, StandardTeam& team) {
    os << team.qb.getName() << std::endl
       << team.rb1.getName() << ", " << team.rb2.getName() << std::endl
       << team.wr1.getName() << ", " << team.wr2.getName() << ", " << team.wr3.getName() << std::endl
       << team.te.getName() << std::endl << team.fl.getName() << std::endl
    << team.de.getName() << "     Projected: " << team.projScore;
    return os;
}

bool operator<(const StandardTeam& lhs, const StandardTeam& rhs) {
    if (lhs.projScore < rhs.projScore) { return true; }
    return false;
}

bool operator==(const StandardTeam& lhs, const StandardTeam& rhs) {
   int equalCounter = 0;
   if (lhs.qb.getName() == rhs.qb.getName()) equalCounter += 1;
   if (lhs.de.getName() == rhs.de.getName()) equalCounter += 1;
   if (lhs.te.getName() == rhs.te.getName() ||
        lhs.te.getName() == rhs.fl.getName()) equalCounter += 1;
   if (lhs.rb1.getName() == rhs.rb1.getName() ||
        lhs.rb1.getName() == rhs.rb2.getName() ||
        lhs.rb1.getName() == rhs.fl.getName()) equalCounter += 1;
   if (lhs.rb2.getName() == rhs.rb1.getName() ||
        lhs.rb2.getName() == rhs.rb2.getName() ||
        lhs.rb2.getName() == rhs.fl.getName()) equalCounter += 1;
   if (lhs.wr1.getName() == rhs.wr1.getName() ||
        lhs.wr1.getName() == rhs.wr2.getName() ||
        lhs.wr1.getName() == rhs.wr3.getName() ||
        lhs.wr1.getName() == rhs.fl.getName()) equalCounter += 1;
    if (lhs.wr2.getName() == rhs.wr1.getName() ||
        lhs.wr2.getName() == rhs.wr2.getName() ||
        lhs.wr2.getName() == rhs.wr3.getName() ||
        lhs.wr2.getName() == rhs.fl.getName()) equalCounter += 1;
    if (lhs.wr3.getName() == rhs.wr1.getName() ||
        lhs.wr3.getName() == rhs.wr2.getName() ||
        lhs.wr3.getName() == rhs.wr3.getName() ||
        lhs.wr3.getName() == rhs.fl.getName()) equalCounter += 1;
    if (lhs.fl.getName() == rhs.wr1.getName() ||
        lhs.fl.getName() == rhs.wr2.getName() ||
        lhs.fl.getName() == rhs.wr3.getName() ||
        lhs.fl.getName() == rhs.rb1.getName() ||
        lhs.fl.getName() == rhs.wr2.getName() ||
        lhs.fl.getName() == rhs.te.getName()) equalCounter += 1;
    if (equalCounter > 3) return true;
    return false;
}

#endif