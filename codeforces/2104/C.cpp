#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.back() == 'A'){
        if(s.front() == 'A' || s[n - 2] == 'A') cout << "Alice\n";
        else cout << "Bob\n";
    }else{
        if(count(s.begin(), s.end(), 'B') >= 2) cout << "Bob\n";
        else cout << "Alice\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t--)
        solve();
    return 0;
}