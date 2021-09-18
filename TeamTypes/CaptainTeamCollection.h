#ifndef CAPTAINTEAMCOLLECTION_H
#define CAPTAINTEAMCOLLECTION_H

#include "CaptainTeam.h"
#include <vector>
#include <iostream>

class CaptainTeamCollection  {
    public:
    std::vector<CaptainTeam> teams;
    private:
    int maxSize;
    double prevMin;

    public:
    CaptainTeamCollection(int n) {
        maxSize = n;
        prevMin = 1000;
    }

    template <typename T>
    void insert_non_max(std::vector<T>& vctr, T n) {
        vctr.push_back(n);
        int i = 0;
        for (i; i < vctr.size(); i++) {
            if (vctr[i] < n) break;
        }
        if (i == vctr.size()) {
            vctr.push_back(n);
            return;
        }
        for (int j = vctr.size() - 1; j > i; j--) {
            vctr[j] = vctr[j-1];
        }
        vctr[i] = n;
    }

    template <typename T>
    void insert_max(std::vector<T>& vctr, T n) {
        vctr.push_back(n);
        int i = 0;
        for (i; i < vctr.size(); i++) {
            if (vctr[i] < n) break;
        }
        for (int j = vctr.size() - 1; j > i; j--) {
            vctr[j] = vctr[j-1];
        }
        vctr[i] = n;
        vctr.pop_back();
    }

    void insert(CaptainTeam& team) {
        if (team.totalPrice > 50000) {
            return;
        }
        if (teams.size() == 0) {
            teams.push_back(team);
            return;
        }
        
        for (int i = 0; i < teams.size(); i++) {
            if (teams[i] == team) {
                if (team.projScore > teams[i].projScore)
                    teams[i] = team;
                return;
            }
        }
        if (teams.size() < maxSize) {
            insert_non_max(teams, team);
            prevMin = teams[teams.size() - 1].projScore;
            return;
        }
        if (team.projScore < prevMin) {
            return;
        }
        else {
            insert_max(teams, team);
            prevMin = teams[teams.size() - 1].projScore;
        }
    }
};

#endif