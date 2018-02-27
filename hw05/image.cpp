#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define REP(i,s,t) for(int i=(s);i<(t);i++)

template<std::size_t R, std::size_t L, std::size_t N>
std::bitset<N> getrange(std::bitset<N> b)
{
    static_assert(R <= L && L <= N, "invalid bitrange");
    b >>= R;            // drop R rightmost bits
    b <<= (N - L + R);  // drop L-1 leftmost bits
    b >>= (N - L);      // shift back into place
    return b;
}

vector<bitset<MAXN>> image;
vector<bitset<MAXN>> pattern;
bool check(int r, int c, int a, int b){
    REP(i,0,a){
        bitset<MAXN> temp = image[r+i] >> c;
        cout << temp.to_string() << endl;
        REP(j,0,b){
            pattern[i]
            if((temp^pattern[i]) <= pattern[i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    char c;
    for (int i=0; i < n; ++i){
        bitset<MAXN> row;
        for (int j=0; j < m; ++j){
            cin >> c;
            row[j] = c == '#' ? 1 : 0;
            // cout << c;
        }
        image.push_back(row);
    }

    int a,b;
    cin >> a >> b;
    for (int i=0; i < a; ++i){
        bitset<MAXN> row;
        for (int j=0; j < b; ++j){
            cin >> c;
            row[j] = c == '.' ? 0 : 1; //bitwise and: if it doesn't matter then
            // cout << c;
        }
        pattern.push_back(row);
    }

    // for(bitset<MAXN> row: image){
    //     cout << row.to_string() << '\n';
    // }
    // for(bitset<MAXN> row: pattern){
    //     cout << row.to_string() << '\n';
    // }

    REP(j,0,m-b+1){
        REP(i,0,n-a+1){
            // cout << (image[i]^pattern[i]) << endl;
            cout << check(i,j,a,b);
        }
    }
}