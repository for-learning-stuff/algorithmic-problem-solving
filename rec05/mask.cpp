#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,l,u;
    bitset<32> m;
    bitset<32> x;
    while(cin >> x >> l >> u){
        for (int i=0; i < 32; ++i){
            if(x[i]){
                for (int j=i+1; j < 32; ++j){
                    m[j] = 1;
                }
                if(m < l){
                    m[i] = 1;
                }
                for (int j=i+1; j < 32; ++j){
                    m[j] = 0;
                }
            }
            else{
                m[i] = 1;
                if(m > u){
                    m[i] = 0;
                }
            }
        }
        cout << m;
    }
}