#include <bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

/*
In mathematics, a Delannoy number D describes the number of paths from the southwest corner (0, 0) of a rectangular grid to the northeast corner (m, n), using only single steps north, northeast, or east.
For Example, D(3, 3) equals 63.

Delannoy number can be used to find:
・Counts the number of global alignments of two sequences of lengths m and n.
・Number of points in an m-dimensional integer lattice that are at most n steps from the origin.
・In cellular automata, the number of cells in an m-dimensional von Neumann neighborhood of radius n.
・Number of cells on a surface of an m-dimensional von Neumann neighborhood of radius n.
*/

int delannoy(int n, int m){
    if(m == 0 || n == 0){
        return 1;
    }

    return delannoy(m - 1, n) + delannoy(m - 1, n - 1) + delannoy(m, n - 1);
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << delannoy(n, m) << endl;
    return 0;
}