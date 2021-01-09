#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
*/

bool isSubsetSum(vector<int> set, int n, int sum){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }

    if(set[n - 1] > sum){
        return isSubsetSum(set, n - 1, sum);
    }

    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main(){
    int n, sum;
    vector<int> set(n);
    cout << "n = ";
    cin >> n;
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "set[" << i << "] = ";
        cin >> set[i];
    }
    cout << "sum = ";
    cin >> sum;
    cout << endl;

    if(isSubsetSum(set, n, sum) == true){
        cout << "Found a subset with sum" << endl;
    }
    else
    {
        cout << "No subset with given sum" << endl;
    }
    
    return 0;
}