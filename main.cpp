#include "PlayerTypes/QB.h"
#include "PlayerTypes/RB.h"
#include "PlayerTypes/WR.h"
#include "PlayerTypes/TE.h"
#include "PlayerTypes/DE.h"
#include "PlayerTypes/FL.h"
#include "TeamTypes/Inputs.h"
#include "TeamTypes/StandardTeamCollection.h"
#include "TeamTypes/Optimizing.h"
#include "TeamTypes/CaptainTeam.h"
#include "TeamTypes/CaptainTeamCollection.h"
#include "TeamTypes/StandardTeam.h"

#include <iostream>
#include <vector>

using namespace std;

void runStandardTeam() {
    cout << "Reading input files..." << endl;
    vector<QB> qbs = readQBs();
    vector<RB> rbs = readRBs();
    vector<WR> wrs = readWRs();
    vector<TE> tes = readTEs();
    vector<DE> des = readDEs();
    vector<FL> fls;
    cout << "Done reading." << endl;

    cout << "Optimizing Vectors..." << endl;
    nBestPlayers(qbs, 5);
    nBestPlayers(rbs, 8);
    nBestPlayers(wrs, 10);
    nBestPlayers(tes, 5);
    nBestPlayers(des, 4);
    nBestPlayers(fls, rbs, wrs, tes);
    cout << "Done optimizing" << endl;

    cout << "How many teams do you want? : ";
    int numTeams;
    cin >> numTeams;
    cout << "Computing best lineups..." << endl;

    //long long timer = 0;
    StandardTeamCollection teams(numTeams);
    for (int i = 0; i < qbs.size(); i++) {
    for (int j1 = 0; j1 < rbs.size(); j1++) {
    for (int j2 = 0; j2 < rbs.size(); j2++) {
    for (int k1 = 0; k1 < wrs.size(); k1++) {
    for (int k2 = 0; k2 < wrs.size(); k2++) {
    for (int k3 = 0; k3 < wrs.size(); k3++) {
    for (int l1 = 0; l1 < tes.size(); l1++) {
    for (int m = 0; m < des.size(); m++) {
    for (int n = 0; n < fls.size(); n++) {
        //cout << timer << endl;
        //timer++;
        if (j1 != j2 && k1 != k2 && k1 != k3 && k2 != k3 &&
            j1 != n && j2 != n && n != (rbs.size() + k1) &&
            n != (rbs.size() + k2) && n != (rbs.size() + k3) &&
            n != (rbs.size() + wrs.size() + l1)) {
                StandardTeam tempTeam(qbs[i], rbs[j1], rbs[j2], wrs[k1], wrs[k2],
                                    wrs[k3], tes[l1], des[m], fls[n]);
                teams.insert(tempTeam);
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    cout << "Writing file..." << endl;
    writeFiles(teams);
}

void runCaptainTeam() {
    cout << "Reading input files..." << endl;
    vector<Captain> cpts; vector<GenericPlayer> players;
    readCaptain(cpts, players);
    cout << "Done reading." << endl;

    cout << "Optimizing vectors..." << endl;
    nBestPlayers(cpts, players, 17);
    cout << "Done optimizing" << endl;

    cout << "How many teams do you want? : ";
    int numTeams;
    cin >> numTeams;
    cout << "Computing best lineups..." << endl;

    CaptainTeamCollection teams(numTeams);
    for (int i = 0; i < cpts.size(); i++) {
    for (int j1 = 0; j1 < players.size(); j1++) {
    for (int j2 = 0; j2 < players.size(); j2++) {
    for (int j3 = 0; j3 < players.size(); j3++) {
    for (int j4 = 0; j4 < players.size(); j4++) {
    for (int j5 = 0; j5 < players.size(); j5++) {
        if (i != j1 && i != j2 && i != j3 && i != j4 && i != j5 &&
            j1 != j2 && j1 != j3 && j1 != j4 && j1 != j5 &&
            j2 != j3 && j2 != j4 && j2 != j5 &&
            j3 != j4 && j3 != j5 && j4 != j5) {
                CaptainTeam tempTeam(cpts[i], players[j1], players[j2],
                                 players[j3], players[j4], players[j5]);
                teams.insert(tempTeam);
            }
    }
    }
    }
    }
    }
    }
    cout << "Writing file..." << endl;
    writeCaptainFiles(teams);
}

int main() {
    cout << "What kind of team do you want?" << endl;
    cout << "1 for a normal team, 2 for a captain team: ";
    int userChoice;
    cin >> userChoice;
    switch(userChoice) {
        case 1:
            runStandardTeam();
            break;
        case 2:
            runCaptainTeam();
            break;
        default:
            cout << "Invalid Choice. Ending Program" << endl;
            return 0;
    }
    
}