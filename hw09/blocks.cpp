#include<bits/stdc++.h>
using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define MAXN 1000000
#define P 1000000007
typedef long long MATRIX[4][4];

long long values[MAXN+1] = {1,1,2,7,15};

int base[5] = {1,1,2,7,15};
MATRIX multiplier = {{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,1,4,2}};
// MATRIX mult = multiplier;
 
void MATRIXmult(MATRIX r, MATRIX a, MATRIX b){
    REP(i,0,4){
        REP(j,0,4){
            r[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[0][2] + a[i][3]*b[3][j];
        }
    }
}

void MATRIXcopy(MATRIX r, MATRIX a){
    REP(i,0,4){
        REP(j,0,4){
            r[i][j] = a[i][j];
        }
    }
}

int main(){
    long long n;
    cin >> n;

    MATRIX r = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

    // log2(10^18) < 60;
    // MATRIXmult(r, multiplier, multiplier);


    while(n > 0){
        MATRIX t;
        if(n & -n){
            copy(&r[0][0], &r[0][0]+16, &t[0][0]);
            MATRIXmult(r, t, multiplier);
        }
        n = n >> 1;
        // printf("%lld\n",n);

        copy(&multiplier[0][0], &multiplier[0][0]+16, &t[0][0]);
        MATRIXmult(multiplier, t, t); // double multiplier
        // m[i] = (m[i-1] + m[i-2] + (4*m[i-3])%P + (2*m[i-4])%P) % P;
    }

    REP(i,0,4){
        REP(j,0,4){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    // cout << m[n]%P;
}