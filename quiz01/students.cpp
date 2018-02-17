#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

map<string, int> sid;
string names[MAXN];
int pre[MAXN], nxt[MAXN];
int main() {
  int n, q; //number of students and number of queries
  cin >> n;
  names[0] = names[n+1] = "-1";
  REP(i,1,n+1) { //loop
    names[i] = i;
    sid[to_string(i)] = i; //name to student id
    pre[i] = i - 1; //previous student
    nxt[i] = i + 1; //next student
  }
  cin >> q;
  while (q--) {
    char op[3], s1[11], s2[11]; //operation, student1, student2
    int a, b; //the ids of the students
    scanf("%s%s", op, s1);
    a = sid[s1];
    cout << op << " " << a;
    if (op[0] == 'l' || op[0] == 'r') {
      // printf("%s\n", names[op[0] == 'l' ? pre[a] : nxt[a]].c_str());
      printf("%d\n", op[0] == 'l' ? pre[a] : nxt[a]);
    } else if (op[1] == 'l'){
        nxt[pre[a]] = nxt[a];
        pre[nxt[a]] = pre[a];
        pre[a] = nxt[0];
        nxt[a] = nxt[ ]

    } else if (op[1] == 'r'){
        
    }

    // } else if (op[0] == 'e') {
    //   nxt[pre[a]] = nxt[a];
    //   pre[nxt[a]] = pre[a];
    // } else if (op[0] == 'x') {
    //   scanf("%s", s2);
    //   b = sid[s2];
    //   swap(names[a], names[b]);
    //   swap(sid[s1], sid[s2]);
    // }
  }
  return 0;
}
