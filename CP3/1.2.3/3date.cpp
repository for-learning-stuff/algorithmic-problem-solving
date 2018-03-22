// Date string to object representing time

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main(){
    tm t;
    const char date[] = "9 August 2010";
    strptime(date, "%d %b %Y", &t);
    cout << t.tm_wday;
}                                                                                                                                                                                                                                                                                                                                                            