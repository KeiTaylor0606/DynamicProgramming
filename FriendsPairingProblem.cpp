#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*
Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. 
Find out the total number of ways in which friends can remain single or can be paired up.
*/

// Returns count of ways n people 
// can remain single or paired up. 
int countFriendsPairing(int n){
    int dp[n + 1];

    // Filling dp[] in bottom-up manner using 
    // recursive formula explained above. 
    for(int i = 0; i <= n; i++){
        if(i <= 2){
            dp[i] = i;
        }
        else{
            dp[i] = dp[i - 1] + (i - 1)*dp[i - 2];
        }     
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << countFriendsPairing(n) << endl;
    return 0;
}