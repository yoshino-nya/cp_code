#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a{2, 2, 4, 1, 1, 2};
    ranges::unique(a);
    for(auto x : a)
        cout << x << " ";
    cout << "\n";
    
}