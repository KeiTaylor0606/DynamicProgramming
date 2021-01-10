#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*
In combinatorics, the Eulerian Number A(n, m), is the number of permutations of the numbers 1 to n in which exactly m elements are greater than previous element.
For example, there are 4 permutations of the number 1 to 3 in which exactly 1 element is greater than the previous elements.
*/

int eulerian(int n, int m){
    if(m >= n || n == 0){
        return 0;
    }
    if(m == 0){
        return 1;
    }

    return (n - m)*eulerian(n - 1, m - 1) + (m + 1)*eulerian(n - 1, m);
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << eulerian(n, m) << endl;
    return 0;
}