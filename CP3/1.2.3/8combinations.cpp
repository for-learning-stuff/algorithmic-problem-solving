// Generate subsets of a set of numbers

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// https://stackoverflow.com/a/9430993
int main(){
    int n = 4;

    vector<int> numbers(n);
    iota(numbers.begin(), numbers.end(), 0);

    vector<bool> v(n);
    for (int r = 0; r <= n; ++r){
        fill(v.end() - r, v.end(), true);
        // set r LSBs
        
        do {
            for (int i = 0; i < n; ++i){
                if(v[i]){
                    // Print corresponding members
                    cout << numbers[i];
                }
            }
            cout << " ";
        } while (next_permutation(v.begin(),v.end()));
        cout << endl;
    }
}


