// 
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int main(){
    iii A = iii(ii(5,24), -1982);
    // iii A = make_pair(ii(5,24), -1982);
    iii B = make_pair(ii(5,24), -1980);
    iii C = make_pair(ii(11,13), -1983);

    vector<iii> birthdays;
    birthdays.push_back(A); birthdays.push_back(B); birthdays.push_back(C);
    sort(birthdays.begin(), birthdays.end());
    // Orders by the the ii pairs, which then compares the first, then second 
}