#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
#define MAX 100
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*Rencontres Number (Counting partial derangements)*/

void binomialCoeff(int C[][MAX], int n, int k){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(i, k); j++){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
}

int RencontresNumber(int C[][MAX], int n, int m){
    int dp[n + 1][m + 1] = {0};

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(j <= i){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 1 && j == 0){
                    dp[i][j] = 0;
                }
                else if(j == 0){
                    dp[i][j] = (i - 1)*(dp[i - 1][0] + dp[i - 2][0]);
                }
                else{
                    dp[i][j] = C[i][j]*dp[i - j][0];
                }
            }
        }
    }

    return dp[n][m];
}

int main(){
    int n, m;
    cin >> n >> m;

    int C[MAX][MAX];
    binomialCoeff(C, n, m);

    cout << RencontresNumber(C, n, m) << endl;
    return 0;
}