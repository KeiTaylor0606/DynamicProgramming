#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*
Given an array of non-negative integers and a value sum, determine if there is a subset of the given set with sum equal to given sum.
*/

bool isSubsetSum(vector<int> set, int n, int sum){
    bool subset[2][sum + 1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(j == 0){
                subset[i%2][j] = true;
            }
            else if(i == 0){
                subset[i%2][j] = false;
            }
            else if(set[i%2] <= j){
                subset[i % 2][j] = subset[(i + 1) % 2][j - set[i - 1]] || subset[(i + 1) % 2][j]; 
            }
            else{
                subset[i % 2][j] = subset[(i + 1) % 2][j];
            }
        }
    }

    return subset[n%2][sum];
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    cout << endl;
    vector<int> set(n);
    for(int i = 0; i < n; i++){
        cout << "set[" << i << "] = ";
        cin >> set[i];
    }
    cout << endl;

    int sum;
    cout << "sum = ";
    cin >> sum;
    cout << endl;

    if(isSubsetSum(set, n, sum)){
        cout << "There exists a subset with given sum" << endl;
    }
    else{
        cout << "No subset exists with given sum" << endl;
    }
    return 0;
}