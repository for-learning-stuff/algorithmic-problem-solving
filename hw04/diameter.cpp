#include<bits/stdc++.h>
using namespace std;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define MAXN 50

vector<int> t1[10];
vector<int> t2[MAXN];
int depth[MAXN];

//depth+1, element
pair<int,int> deepest(int i, int parent = -1){
    pair<int,int> m(0,i);

    for(int j: t1[i]){
        if(j == parent) continue;
        m = max(m, deepest(j, i));
    }

    if (t1[i].size() > 1 || parent == -1)
        m.first+=1;
    // cout << i << " " << m.first  << " " << m.second << endl;
        // cout << m;
    return m;
}


int main(){
    int n;
    cin >> n;
    int a, b;
    REP(i,1,n){
        cin >> a >> b;
        t1[a].push_back(b);
        t1[b].push_back(a);
    }
    int m;
    cin >> m;
    REP(i,1,m){
        cin >> a >> b;
        t2[a].push_back(b);
        t2[b].push_back(a);
    }

    REP(i,1,10){
        depth[i]=0;
    }
    // cout << 4 << deepest(4).second << endl;

    // REP(i,1,n+1){
    //     cout << i << deepest(i).second << " " << deepest(i).first << endl;
    // }

    for (int j = 1; j < 10; ++j){
        // cout << v.size() << endl;
        vector<int> v = t1[j];
        for (int i = 0; i < v.size(); ++i){
            if (
            depth[v[i]] = max(depth[v[i]], depth[j]+1);
        }
        REP(i,1,10){
            cout << depth[i];
        }
        cout << endl;
    }

    for (vector<int> v: t1){
        // cout << v.size() << endl;
        for (int i: v){
            cout << i << " ";
        }
        cout  << endl;
    }
}