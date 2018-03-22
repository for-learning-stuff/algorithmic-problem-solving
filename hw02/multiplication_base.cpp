#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int p = 1000000007;

void powMod(map<int, int>& powers, int base, int exponent){
    long long exp = 1;
    for (int i = 0; i < exponent; i++){
        powers.insert(pair<int,int>(i, exp));
        exp *= base;
        exp = exp % p;
        // cout << exp << endl;
    }
}

long long toInt(string s, int base, map<int, int>& powers){
    long long ret = 0;
    for(int i = 0; i < s.length(); i++){
        int to62;
        if(s[i] >= 97){
            to62 = s[i]-87;
        } else if(s[i] >= 65){
            to62 = s[i]-29;
        } else {
            to62 = s[i]-48;
        }
        long long ex = powers[s.length()-i-1];
        // cout << s.length()-i-1 << " " << ex << " " << to62 << " Before: " << ret << " After: ";
        ret += (1l * ex * to62);
        // cout << ret << endl;
        ret = ret % p;
    }
    return ret;
}

int main(){
    int base;
    scanf("%d", &base);
    string a;
    string b;
    cin >> a >> b;
    map<int, int> powers;
    int m = max(a.length(), b.length());
    powMod(powers, base, m);

    int aInt = toInt(a, base, powers);
    int bInt = toInt(b, base, powers);
    // cout << aInt << " " << bInt << endl;
    cout << 1l * (aInt % p) * (bInt % p) % p<< endl;
    return 0;
}