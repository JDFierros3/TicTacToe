#include "agent.h"
using namespace std;
Agent::Agent(){

}

char Agent::opponate(char c){
    if(c=='X'){
        return 'O';
    }
    else{
        return 'X';
    }
}

int Agent::utility(State s){
    if(checkWin(s.getboard(),s.getTurn()))
        return 1;
    if(checkWin(s.getboard(),opponate(s.getTurn())))
        return -1;
    return 0;
}

bool Agent::checkWin(string p,char turn){
    char c0 =p.at(0);
    char c1 =p.at(1);
    char c2 =p.at(2);
    char c3 =p.at(3);
    char c4 =p.at(4);
    char c5 =p.at(5);
    char c6 =p.at(6);
    char c7 =p.at(7);
    char c8 =p.at(8);
    if((c0==turn&&c1==turn&&c2==turn)||(c3==turn&&c4==turn&&c5==turn)||(c6==turn&&c7==turn&&c8==turn))
        return true;
    if((c0==turn&&c3==turn&&c6==turn)||(c1==turn&&c4==turn&&c7==turn)||(c2==turn&&c5==turn&&c8==turn))
        return true;
    if((c0==turn&&c4==turn&&c8==turn)||(c6==turn&&c4==turn&&c2==turn))
        return true;
    return false;
}

bool Agent::gameOver(string board){
    for(int i=0;i<board.length();i++){
        if(board.at(i)=='.')
            return false;
    }
    return true;
}

void Agent::getMoves(State s,moveList& sl){
    int sz= s.getboard().length();
    for(int i=0;i<sz;i++){
        if(s.getboard().at(i)=='.'){
            sl.push_back(i);
        }
    }
}

int Agent::maxMove(State p,int& bestMove){
    if(gameOver(p.getboard())||checkWin(p.getboard(),p.getTurn())){
        return utility(p);
    }
    moveList movelist;
    getMoves(p,movelist);
    int nmoves= movelist.size();
    int rating= -1000;
    for(int i=0; i<nmoves;i++){
        int move = movelist[i];
        p.setBoard(move);
        int oBestMove;
        int curRating = -maxMove(p,oBestMove);
        if(curRating>rating){
            rating = curRating;
            bestMove=move;
        }
        p.setBoard(move,'.');
    }
    return rating;
}

int Agent::miniMax(State s){
    int bestMove;
    int i = 0;
    i = maxMove(s, bestMove);
    //cout<<"i is "<<i<<endl;
    return bestMove;
}

