#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*
In combinatorial mathematics, the Lobb number Lm, n counts the number of ways that n + m open parentheses can be arranged to form the start of a valid sequence of balanced parentheses.
The Lobb number are parameterized by two non-negative integers m and n with n >= m >= 0. 
It can be obtained by: L_{m,n} = (2m+1)/(m+n+1){2n ,(m+n)} 
Lobb Number is also used to count the number of ways in which n + m copies of the value +1 and n – m copies of the value -1 may be arranged into a sequence such that all of the partial sums of the sequence are non- negative.
*/

int binomialCoeff(int n, int k){
    int C[n + 1][k + 1];

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

    return C[n][k];
}

int lobb(int n, int m){
    return ((2*m + 1)*binomialCoeff(2*n, m + n) / (m + n + 1));
}

int main(){
    int n, m;
    cin >> n >> m;

    cout << lobb(n, m) << endl;
    
    return 0;
}