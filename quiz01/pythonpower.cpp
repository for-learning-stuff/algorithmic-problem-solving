#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int p = 1000000007;

long long powMod(long long base, long long exponent){
    long long exp = 1;
    for (long long i = 0; i < exponent; i++){
        exp *= base;
        exp = exp % p;
        // cout << exp << endl;
    }
    return exp;
}

int main(){;
    long long a, b;
    char c;
    cin >> a >> c >> c >> b;
    cout << powMod(a,b);
    // cout << powMod(1,0) << endl;
    // cout << powMod(2,3) << endl;
    // cout << powMod(10,2) << endl;
    // cout << powMod(10,10) << endl;
    // long long i = 9876543210;
    // cout << powMod(i,100);
}