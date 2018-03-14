#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,t) for(int i=(s);i<(t);i++)

#define MAXN 16
#define MAXM 16
bool grid[MAXN+1][MAXM+1] = {};
bool on[MAXN+1][MAXM+1] = {};
// bool grid[MAXN][MAXM] = {};
int num = 0;

int countbulbs(int n, int m){
    int c = 0;
    REP(i,0,n){
        REP(j,0,m){
            c += grid[i][j];
        }
    }
    return c;
}

void printbulbs(){
    REP(i,0,4){
        REP(j,0,4){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void printon(){
    REP(i,0,4){
        REP(j,0,4){
            if (on[i][j]){
                printf("(%d,%d), ",i,j);
            }
        }
    }
    cout << endl;
}


void flip(int i, int j){
    on[i][j] = !on[i][j];
    if(i-1>=0)
    grid[i-1][j] = !grid[i-1][j];
    if(j-1>=0)
    grid[i][j-1] = !grid[i][j-1];
    grid[i][j] = !grid[i][j];
    // There is extra space in the grid
    grid[i][j+1] = !grid[i][j+1];
    grid[i+1][j] = !grid[i+1][j];
}

// complete search
int placebulb(int i, int j, int n, int m){
    // printf("row: %d, col: %d\n", i, j);
    if (i == n) return (int)1E9; // one past end of rows
    
    flip(i,j);
    printon();
    printbulbs();
    int c = countbulbs(n,m);

    int b = (int)1E9;
    if (c == 0){
        flip(i,j);
        return 1;
    }

    // same row
    REP(y,1,m-j){
        b = min(b, placebulb(i,j+y,n,m));
    }
    
    // rest of board
    REP(x,1,n-i){
        REP(y,0,m){
            b = min(b, placebulb(i+x,y,n,m));
        }
    }

    if(b == (int)1E9){
        flip(i,j);
        return (int)1E9;
    }
    else{
        flip(i,j);
        return b+1;
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    char c;
    REP(i,0,n){
        REP(j,0,m){
            cin >> c;
            if(c == '*'){
                grid[i][j] = 1;
            }
        }
    }

    int b = (int)1E9;
    REP(i,0,n){
        REP(j,0,m){
            b = min(b,placebulb(i,j,n,m));
        }
    } 
    if (b == (int)1E9){
        cout << -1;
    } else {
        cout << b;
    }

}