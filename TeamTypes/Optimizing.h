#ifndef OPTIMIZING_H
#define OPTIMIZING_H

#include <iostream>
#include <vector>
#include "StandardTeam.h"
#include "CaptainTeam.h"

void nBestPlayers(std::vector<QB>& players, int n) {
    std::vector<double> ptDensity;
    std::vector<int> indexes;
    std::vector<QB> playersCopy = players;
    for (int i = 0; i < playersCopy.size(); i++) {
        ptDensity.push_back(playersCopy[i].getProj() / playersCopy[i].getPrice());
    }
    for (int i = 0; i < n; i++) {
        double tempMax = ptDensity[0];
        int tempInd = 0;
        for (int i = 0; i < playersCopy.size(); i++) {
            if (ptDensity[i] > tempMax) {
                tempMax = ptDensity[i];
                tempInd = i;
            }
        }
        ptDensity[tempInd] = 0;
        indexes.push_back(tempInd);
    }
    std::vector<QB> returnPlayers;
    for (int i = 0; i < n; i++) {
        returnPlayers.push_back(players[indexes[i]]);
    }
    players = returnPlayers;
}

void nBestPlayers(std::vector<RB>& players, int n) {
    std::vector<double> ptDensity;
    std::vector<int> indexes;
    std::vector<RB> playersCopy = players;
    for (int i = 0; i < playersCopy.size(); i++) {
        ptDensity.push_back(playersCopy[i].getProj() / playersCopy[i].getPrice());
    }
    for (int i = 0; i < n; i++) {
        double tempMax = ptDensity[0];
        int tempInd = 0;
        for (int i = 0; i < playersCopy.size(); i++) {
            if (ptDensity[i] > tempMax) {
                tempMax = ptDensity[i];
                tempInd = i;
            }
        }
        ptDensity[tempInd] = 0;
        indexes.push_back(tempInd);
    }
    std::vector<RB> returnPlayers;
    for (int i = 0; i < n; i++) {
        returnPlayers.push_back(players[indexes[i]]);
    }
    players = returnPlayers;
}

void nBestPlayers(std::vector<WR>& players, int n) {
    std::vector<double> ptDensity;
    std::vector<int> indexes;
    std::vector<WR> playersCopy = players;
    for (int i = 0; i < playersCopy.size(); i++) {
        ptDensity.push_back(playersCopy[i].getProj() / playersCopy[i].getPrice());
    }
    for (int i = 0; i < n; i++) {
        double tempMax = ptDensity[0];
        int tempInd = 0;
        for (int i = 0; i < playersCopy.size(); i++) {
            if (ptDensity[i] > tempMax) {
                tempMax = ptDensity[i];
                tempInd = i;
            }
        }
        ptDensity[tempInd] = 0;
        indexes.push_back(tempInd);
    }
    std::vector<WR> returnPlayers;
    for (int i = 0; i < n; i++) {
        returnPlayers.push_back(players[indexes[i]]);
    }
    players = returnPlayers;
}

void nBestPlayers(std::vector<TE>& players, int n) {
    std::vector<double> ptDensity;
    std::vector<int> indexes;
    std::vector<TE> playersCopy = players;
    for (int i = 0; i < playersCopy.size(); i++) {
        ptDensity.push_back(playersCopy[i].getProj() / playersCopy[i].getPrice());
    }
    for (int i = 0; i < n; i++) {
        double tempMax = ptDensity[0];
        int tempInd = 0;
        for (int i = 0; i < playersCopy.size(); i++) {
            if (ptDensity[i] > tempMax) {
                tempMax = ptDensity[i];
                tempInd = i;
            }
        }
        ptDensity[tempInd] = 0;
        indexes.push_back(tempInd);
    }
    std::vector<TE> returnPlayers;
    for (int i = 0; i < n; i++) {
        returnPlayers.push_back(players[indexes[i]]);
    }
    players = returnPlayers;
}

void nBestPlayers(std::vector<DE>& players, int n) {
    std::vector<double> ptDensity;
    std::vector<int> indexes;
    std::vector<DE> playersCopy = players;
    for (int i = 0; i < playersCopy.size(); i++) {
        ptDensity.push_back(playersCopy[i].getProj() / playersCopy[i].getPrice());
    }
    for (int i = 0; i < n; i++) {
        double tempMax = ptDensity[0];
        int tempInd = 0;
        for (int i = 0; i < playersCopy.size(); i++) {
            if (ptDensity[i] > tempMax) {
                tempMax = ptDensity[i];
                tempInd = i;
            }
        }
        ptDensity[tempInd] = 0;
        indexes.push_back(tempInd);
    }
    std::vector<DE> returnPlayers;
    for (int i = 0; i < n; i++) {
        returnPlayers.push_back(players[indexes[i]]);
    }
    players = returnPlayers;
}

void nBestPlayers(std::vector<FL>& players, std::vector<RB>& rbs,
                  std::vector<WR>& wrs, std::vector<TE> tes) {
    for (int i = 0; i < rbs.size(); i++) {
        players.push_back(FL(rbs[i].getName(), rbs[i].getProj(),
                   rbs[i].getPrice(), "RB"));
    }
    for (int i = 0; i < wrs.size(); i++) {
        players.push_back(FL(wrs[i].getName(), wrs[i].getProj(),
                   wrs[i].getPrice(), "WR"));
    }
    for (int i = 0; i < tes.size(); i++) {
        players.push_back(FL(tes[i].getName(), tes[i].getProj(),
                   tes[i].getPrice(), "TE"));
    }
}

void nBestPlayers(std::vector<Captain>& cpts, std::vector<GenericPlayer>& players, int n) {
    std::vector<double> ptDensity;
    std::vector<int> indexes;
    std::vector<GenericPlayer> playersCopy = players;
    for (int i = 0; i < playersCopy.size(); i++) {
        ptDensity.push_back(playersCopy[i].getProj() / playersCopy[i].getPrice());
    }
    for (int i = 0; i < n; i++) {
        double tempMax = ptDensity[0];
        int tempInd = 0;
        for (int i = 0; i < playersCopy.size(); i++) {
            if (ptDensity[i] > tempMax) {
                tempMax = ptDensity[i];
                tempInd = i;
            }
        }
        ptDensity[tempInd] = 0;
        indexes.push_back(tempInd);
    }
    std::vector<GenericPlayer> returnPlayers;
    for (int i = 0; i < n; i++) {
        returnPlayers.push_back(players[indexes[i]]);
    }
    players = returnPlayers;

    std::vector<Captain> returnCpts;
    for (int i = 0; i < n; i++) {
        returnCpts.push_back(Captain(players[i].getName(),
                    players[i].getProj(), players[i].getPrice()));
    }
    cpts = returnCpts;
}

#endif