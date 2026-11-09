#include <bits/stdc++.h>

using std :: vector;

int main() {
    vector < int > a; a = {1, 2, 3, 4, 5}; 
    int *p = &a[0]; 
    std :: cout << *p << '\n'; 
    *p ++; 
    for(int &x : a) std :: cout << x << ' '; 
}