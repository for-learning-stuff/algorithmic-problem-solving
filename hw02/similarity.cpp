#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

void printboard(vector< vector<char> >& board){
    for (auto row: board){
        for (char c: row){
            cout << c;
        }
        cout << endl;
    }
}

auto rotate(vector< vector<char> >& board){
    for (int c = 0; c < board[0].size(); ++c){
        for (int r = board.size(); r > 0; --r){
            cout << board[r][c];
        }
        cout << endl;
    }
}

auto flip(vector< vector<char> >& board){
    
}

auto translate(vector< vector<char> >& board){
    
}

int main(){
    int ar, ac;
    cin >> ar >> ac;
    // cout << ar << ac;
    char c;
    vector< vector<char> > boardA;
    for (int i = 0; i < ar; ++i){
        vector<char> r;
        for (int j = 0; j < ac; ++j){
            cin >> c;
            r.push_back(c);
        }
        boardA.push_back(r);
    }

    printboard(boardA);
    rotate(boardA);
    // printboard(rotate(boardA));

    return 0;
}