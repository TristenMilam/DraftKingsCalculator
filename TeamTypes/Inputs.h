#ifndef INPUTS_H
#define INPUTS_H

#include "../PlayerTypes/QB.h"
#include "../PlayerTypes/RB.h"
#include "../PlayerTypes/WR.h"
#include "../PlayerTypes/TE.h"
#include "../PlayerTypes/DE.h"
#include "../PlayerTypes/FL.h"
#include "../PlayerTypes/Captain.h"
#include "../PlayerTypes/GenericPlayer.h"
#include "StandardTeamCollection.h"
#include "CaptainTeamCollection.h"
#include <fstream>
#include <vector>

std::vector<QB> readQBs() {
    //Reads in n QB's from the file
    std::ifstream inFS {"InputStats/QB.txt"};
    std::string tempName1, tempName2, tempName;
    double tempProj;
    short tempPrice;
    std::vector<QB> qbList;
    while (inFS >> tempName1 >> tempName2 >> tempProj >> tempPrice) {
        tempName = tempName1 + " " + tempName2;
        qbList.push_back(QB(tempName, tempProj, tempPrice));
    }
    return qbList;
}

std::vector<RB> readRBs() {
    //Reads in n RB's from the file
    std::ifstream inFS {"InputStats/RB.txt"};
    std::string tempName1, tempName2, tempName;
    double tempProj;
    short tempPrice;
    std::vector<RB> RBList;
    while (inFS >> tempName1 >> tempName2 >> tempProj >> tempPrice) {
        tempName = tempName1 + " " + tempName2;
        RBList.push_back(RB(tempName, tempProj, tempPrice));
    }
    return RBList;
}

std::vector<WR> readWRs() {
    //Reads in n WR's from the file
    std::ifstream inFS {"InputStats/WR.txt"};
    std::string tempName1, tempName2, tempName;
    double tempProj;
    short tempPrice;
    std::vector<WR> WRList;
    while (inFS >> tempName1 >> tempName2 >> tempProj >> tempPrice) {
        tempName = tempName1 + " " + tempName2;
        WRList.push_back(WR(tempName, tempProj, tempPrice));
    }
    return WRList;
}

std::vector<TE> readTEs() {
    //Reads in n TE's from the file
    std::ifstream inFS {"InputStats/TE.txt"};
    std::string tempName1, tempName2, tempName;
    double tempProj;
    short tempPrice;
    std::vector<TE> TEList;
    while (inFS >> tempName1 >> tempName2 >> tempProj >> tempPrice) {
        tempName = tempName1 + " " + tempName2;
        TEList.push_back(TE(tempName, tempProj, tempPrice));
    }
    return TEList;
}

std::vector<DE> readDEs() {
    //Reads in n DE's from the file
    std::ifstream inFS {"InputStats/DE.txt"};
    std::string tempName1, tempName2, tempName;
    double tempProj;
    short tempPrice;
    std::vector<DE> DEList;
    while (inFS >> tempName1 >> tempName2 >> tempProj >> tempPrice) {
        tempName = tempName1 + " " + tempName2;
        DEList.push_back(DE(tempName, tempProj, tempPrice));
    }
    return DEList;
}

void readCaptain(std::vector<Captain>& cpts, std::vector<GenericPlayer>& players) {
    std::ifstream inFS {"InputStats/Captain.txt"};
    std::string tempName1, tempName2, tempName;
    double tempProj;
    short tempPrice;
    while (inFS >> tempName1 >> tempName2 >> tempProj >> tempPrice) {
        tempName = tempName1 + " " + tempName2;
        cpts.push_back(Captain(tempName, tempProj, tempPrice));
        players.push_back(GenericPlayer(tempName, tempProj, tempPrice));
    }
}

/*
std::vector<FL> readFLs(int n1, int n2, int n3) {
    //Reads in n FL's from the file
    std::ifstream inFS {"InputStats/RB.txt"};
    std::string tempName1, tempName2, tempName;
    double tempProj;
    short tempPrice;
    std::vector<FL> FLList;
    for (int i = 0; i < n1; i++) {
        inFS >> tempName1 >> tempName2 >> tempProj >> tempPrice;
        tempName = tempName1 + " " + tempName2;
        FLList.push_back(FL(tempName, tempProj, tempPrice, "RB"));
    }
    inFS.close();

    std::ifstream inFS2 {"InputStats/WR.txt"};
    for (int i = 0; i < n2; i++) {
        inFS2 >> tempName1 >> tempName2 >> tempProj >> tempPrice;
        tempName = tempName1 + " " + tempName2;
        FLList.push_back(FL(tempName, tempProj, tempPrice, "WR"));
    }
    inFS2.close();

    std::ifstream inFS3 {"InputStats/TE.txt"};
    for (int i = 0; i < n2; i++) {
        inFS3 >> tempName1 >> tempName2 >> tempProj >> tempPrice;
        tempName = tempName1 + " " + tempName2;
        FLList.push_back(FL(tempName, tempProj, tempPrice, "TE"));
    }
    inFS2.close();

    return FLList;
}
*/

void writeFiles(StandardTeamCollection& teams) {
    std::ofstream outFS {"OutputStats/best_lineups.txt"};
    /*
    std::list<StandardTeam>::iterator it;
    it = teams.mpqList.begin();
    while (it != teams.mpqList.end()) {
        outFS << *it << std::endl << std::endl;
    }
    */
   for (int i = 0; i < teams.teams.size(); i++) {
       outFS << teams.teams[i] << std::endl << std::endl;
   }
}

void writeCaptainFiles(CaptainTeamCollection& teams) {
    std::ofstream outFS {"OutputStats/best_captain_lineups.txt"};
   for (int i = 0; i < teams.teams.size(); i++) {
       outFS << teams.teams[i] << std::endl << std::endl;
   }
}

#endif