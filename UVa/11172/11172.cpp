// 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a, b;
    while (n--){
        cin >> a >> b;
        printf("%c\n", a > b ? '>' : a < b ? '<' : '='); // Figured it was ternary operators
    }
}