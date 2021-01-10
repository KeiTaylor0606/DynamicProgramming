#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*
The Entringer Number E(n, k) are the number of permutations of {1, 2, …, n + 1}, starting with k + 1, which, after initially falling, alternatively fall then rise.
*/

int zigzag(int n, int k){
    if(n == 0 && k == 0){
        return 1;
    }
    if(k == 0){
        return 0;
    }

    return zigzag(n, k - 1) + zigzag(n - 1, n - k);
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << zigzag(n, k) << endl;
    return 0;
}