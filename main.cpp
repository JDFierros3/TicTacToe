#include <iostream>
#include "agent.h"
#include <algorithm>
using namespace std;

void print(State s){
    for(int i=0;i<s.getboard().length();i++){
            cout<<s.getboard().at(i);
            if(i==2||i==5||i==8)
            cout<<endl;
    }
}

void print(int move,State s){
    for(int i=0;i<s.getboard().length();i++){
        if(i==move)
            cout<<s.getTurn();
        else
            cout<<s.getboard().at(i);
    }
}

char change(char val){
    if(val=='X')
        val='O';
    else
        val='X';
}

int main(int argc,char *argv[]) {
    if(argc!=2){
	cout<<"Pass the board state as a command line argument. Use '.' as empty spaces, 'X' as your move."<<endl;
	exit(0);
    }else{
    	string m = argv[1];
	if(m.length()!=9){
	   cout<<"Provide a board state of length nine. Use '.' as empty spaces, 'X' as your move."<<endl;
	   exit(0);
	}
	else{
    	    Agent a;
    	    State s(m,'O');
            int move;
   	    move = a.miniMax(s);
    	    print(move,s);
            s.setBoard(move);
    	    //return s.getboard();
	    cout<<endl;
            return 0;
	}
    }
}
