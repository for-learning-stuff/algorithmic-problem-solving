#include<bits/stdc++.h>
using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define MAXN 1000000
#define P 1000000007
typedef long long MATRIX[][];

long long values[MAXN+1] = {1,1,2,7,15};

int base[5] = {1,1,2,7,15};
MATRIX multiplier = {{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,1,4,2}};
MATRIX mult = multiplier;
 
MATRIX MATRIXmult(MATRIX a, MATRIX b){
    MATRIX r; // will go out of scope you dimwit
    REP(i,0,4){
        REP(j,0,4){
            r[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[0][2] + a[i][3]*b[3][j];
        }
    }
    return r;
}

int main(){
    long long n;
    cin >> n;

    MATRIX r;

    // log2(10^18) < 60
    // mult = MATRIXmult(mult, mult);

    REP(i,0,4){
        REP(j,0,4){
            cout << mult[i][j];
        }
        cout << endl;
    }

    // REP(i,0,61){
    //     if(n & -n){

    //     }
    //     n = n >> 1;
    //     printf("%lld\n",n);
    //     mult = MATRIXmult(mult, mult);
    //     // m[i] = (m[i-1] + m[i-2] + (4*m[i-3])%P + (2*m[i-4])%P) % P;
    // }
    // cout << m[n]%P;
}