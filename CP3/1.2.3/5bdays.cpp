// Print out N digits after the decimal of PI

#include <bits/stdc++.h>
using namespace std;

int main(){
    // For loop
    int n;
    cin >> n;
    while(n--){
        char bdayString[13];
        scanf("%12c", bdayString); // not null terminated, security flaw
        char const f[] = "%d, %m, %Y";
        tm t;
        strptime(bdayString,f,&t); 
    };
    
}


