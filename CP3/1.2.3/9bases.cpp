// Base conversions
#include <bits/stdc++.h>
using namespace std;

string convert(string s, int from, int to){
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int decimal = stoi(s,0,from);
    string converted = "";
    while (decimal % to){
        converted += digits[decimal % to];
        decimal -= (decimal % to);
        decimal /= to;
    }
    reverse(begin(converted), end(converted));
    return converted;
}

int main(){
    int baseX = 16;
    int baseY = 10;
    string n = "FF";
    cout << convert(n, baseX, baseY) << "\n";
}