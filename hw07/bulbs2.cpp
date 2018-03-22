#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,t) for(int i=(s);i<(t);i++)

#define MAXN 8
#define MAXM 8
// #define B 64
// #define MAXB ((MAXN+B-1)/B)

// struct Line {
//     int on = 0;
//     vector<Line*> turnedon; //+2
// };

// bool operator<(const Line& lhs, const Line& rhs)
// {
//   return lhs.on < rhs.on;
// }

// priority_queue<Line> lines;

// Line* rows[MAXN];
// Line* cols[MAXM];

// heap of rows+cols
// keep track of what's on/off so it can be updated
// on row = 0
// not on row = 1

bool grid[MAXN][MAXM] = {};

void fliprow(int i){
    REP(j,0,MAXM){
        grid[i][j] = !grid[i][j];
    }
}

void flipcol(int j){
    REP(i,0,MAXN){
        grid[i][j] = !grid[i][j];
    }
}

int main(){
    int n,m,b;
    cin >> n >> m >> b;

    REP(i,0,n){
        rows[i] = new Line();
    }
    REP(i,0,m){
        cols[i] = new Line();
    }

    int b = 0;

    char c;

    REP(i,0,n){

    }

    // REP(i,0,n){
    //     REP(j,0,m){
    //         cin >> c;
    //         if (c == '*'){
    //             rows[i]->on++;
    //             rows[i]->turnedon.push_back(cols[j]);
    //             cols[j]->on++;
    //             cols[i]->turnedon.push_back(rows[i]);
    //         }
    //     }
    // }
}