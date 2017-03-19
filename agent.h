#ifndef AGENT_H
#define AGENT_H
#include "state.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits>
#include <sstream>
using namespace std;
class Agent {
public:
    Agent();
    char opponate(char);
    bool checkWin(string,char);
    bool gameOver(string);
    void getMoves(State,moveList&);
    int maxMove(State,int&);
    int miniMax(State);
    int utility(State);
private:
};

#endif
