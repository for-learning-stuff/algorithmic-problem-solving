#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printboard(vector< vector<char> >& board){
    for (auto row: board){
        for (char c: row){
            cout << c;
        }
        cout << endl;
    }
}

vector< vector<char> > rotate(vector< vector<char> >& board){
    vector< vector<char> > out;
    for (int c = 0; c < board[0].size(); ++c){
        vector<char> row;
        for (int r = board.size()-1; r >= 0; --r){
            row.push_back(board[r][c]);
        }
        out.push_back(row);
    }
    return out;
}
vector< vector<char> > flipHorizontal(vector< vector<char> >& board){
    vector< vector<char> > out;
    for (int r = 0; r < board.size(); ++r){
        vector<char> row;
        for (int c = 0; c < board[0].size(); ++c){
            row.push_back(board[r][board.size()-c-1]);
        }
        out.push_back(row);
    }
    return out;
}
vector< vector<char> > flipVertical(vector< vector<char> >& board){
    vector< vector<char> > out;
    for (int r = 0; r < board.size(); ++r){
        vector<char> row;
        for (int c = 0; c < board[0].size(); ++c){
            row.push_back(board[board.size()-r-1][c]);
        }
        out.push_back(row);
    }
    return out;
}

// board = board undereath, other = moving board
int check(vector< vector<char> >& board, vector< vector<char> >& other, int startrow, int startcol){
    int match = 0;
    int col = startcol;
    int row = startrow;
    for (int r = 0; r < other.size(); ++r){
        for (int c = 0; c < other[0].size(); ++c){
            if (board[row][col] == other[r][c] && other[r][c] == '#'){
                ++match;
            }
            ++col;
            if (col == board[0].size()){
                break;
            }
        }
        col = startcol;
        ++row;
        if (row == board.size()){
            break;
        }
    }
    return match;
}

int loop(vector< vector<char> >& constantboard, vector< vector<char> >& board){
    int maxmatch = 0;
    for (int r = 0; r < constantboard.size(); ++r){
        for (int c = 0; c < constantboard[0].size(); ++c){
            int match = check(constantboard, board, r, c);
            maxmatch = max(match, maxmatch);
        }
    }
    return maxmatch;
}
int revloop(vector< vector<char> >& board, vector< vector<char> >& constantboard){
    return loop(board, constantboard);
}

int main(){
    int ar, ac;
    cin >> ar >> ac;
    // cout << ar << ac;
    char c;
    // int leftmostA = 100000;
    // int topmostA = 100000;
    // int rightmostA = 0;
    // int bottommostA = 0;
    vector< vector<char> > boardA;
    for (int i = 0; i < ar; ++i){
        vector<char> r;
        for (int j = 0; j < ac; ++j){
            cin >> c;
            // setting where to start iterating
            if (c == '#'){
                if (topmostA == 100000){
                    topmostA = i;
                }
                if (i > bottommostA){
                    bottommostA = i;
                }
                if (j < leftmostA){
                    leftmostA = j;
                }
                if (j > rightmostA){
                    rightmostA = j;
                }
            }
            //////////////
            r.push_back(c);
        }
        boardA.push_back(r);
    }
    int br, bc;
    cin >> br >> bc;
    // cout << ar << ac;
    // int leftmostB = 100000;
    // int topmostB = 100000;
    // int rightmostB = 0;
    // int bottommostB = 0;
    vector< vector<char> > boardB;
    for (int i = 0; i < br; ++i){
        vector<char> r;
        for (int j = 0; j < bc; ++j){
            cin >> c;
            // setting where to start iterating
            if (c == '#'){
                if (topmostB == 100000){
                    topmostB = i;
                }
                if (i > bottommostB){
                    bottommostB = i;
                }
                if (j < leftmostB){
                    leftmostB = j;
                }
                if (j > rightmostB){
                    rightmostB = j;
                }
            }
            //////////////
            r.push_back(c);
        }
        boardB.push_back(r);
    }

    /////////////////////////////////////

    int match = 0;

    vector< vector<char> > r2 = rotate(boardA);
    vector< vector<char> > r3 = rotate(r2);
    vector< vector<char> > r4 = rotate(r3);
    vector< vector<char> > h1 = flipHorizontal(boardA);
    vector< vector<char> > v1 = flipVertical(boardA);
    vector< vector<char> > d1 = flipVertical(h1);
    vector< vector<char> > h2 = flipHorizontal(r2);
    vector< vector<char> > v2 = flipVertical(r2);
    vector< vector<char> > d2 = flipVertical(h2);
    vector< vector<char> > h3 = flipHorizontal(r3);
    vector< vector<char> > v3 = flipVertical(r3);
    vector< vector<char> > d3 = flipVertical(h3);
    vector< vector<char> > h4 = flipHorizontal(r4);
    vector< vector<char> > v4 = flipVertical(r4);
    vector< vector<char> > d4 = flipVertical(h4);

    match = loop(boardB, boardA);
    match = max(match, loop(boardB, r2));
    match = max(match, loop(boardB, r3));
    match = max(match, loop(boardB, r4));
    match = max(match, loop(boardB, h1));
    match = max(match, loop(boardB, h2));
    match = max(match, loop(boardB, h3));
    match = max(match, loop(boardB, h4));
    match = max(match, loop(boardB, v1));
    match = max(match, loop(boardB, v2));
    match = max(match, loop(boardB, v3));
    match = max(match, loop(boardB, v4));
    match = max(match, loop(boardB, d1));
    match = max(match, loop(boardB, d2));
    match = max(match, loop(boardB, d3));
    match = max(match, loop(boardB, d4));

    match = max(match, loop(boardA, boardB));
    match = max(match, revloop(boardB, r2));
    match = max(match, revloop(boardB, r3));
    match = max(match, revloop(boardB, r4));
    match = max(match, revloop(boardB, h1));
    match = max(match, revloop(boardB, h2));
    match = max(match, revloop(boardB, h3));
    match = max(match, revloop(boardB, h4));
    match = max(match, revloop(boardB, v1));
    match = max(match, revloop(boardB, v2));
    match = max(match, revloop(boardB, v3));
    match = max(match, revloop(boardB, v4));
    match = max(match, revloop(boardB, d1));
    match = max(match, revloop(boardB, d2));
    match = max(match, revloop(boardB, d3));
    match = max(match, revloop(boardB, d4));

    cout << match;
    return 0;
}