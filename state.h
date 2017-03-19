#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <vector>
class State;
typedef std::vector<int> moveList;
class State {
public:
    State(std::string s,char c){
        board = s;
        turn =c;
    }
    void setBoard(int i){
        board.at(i)=turn;
        if(turn =='X')
            turn = 'O';
        else{
            turn = 'X';
        }
    }
    void setBoard(int i,char c){
        board.at(i)=c;
        if(turn =='X')
            turn = 'O';
        else{
            turn = 'X';
        }
        //turn = opponate(turn);
    }
    std::string getboard(){return board;}
    char getTurn(){return turn;}
private:
    std::string board;
    char turn;
};
#endif
