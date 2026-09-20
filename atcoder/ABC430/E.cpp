#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    string s, t;
    cin >> s >> t;
    s = s + s;
    vector<int> nxt(t.size() + 1);
    for(int i = 1; i < t.size(); i++){
        int j = nxt[i];
        while(j && t[i] != t[j])
            j = nxt[j];
        if(t[i] == t[j]) nxt[i + 1] = j + 1;
        else nxt[i + 1] = 0;
    }
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        while(j && s[i] != t[j])
            j = nxt[j];
        if(s[i] == t[j]) j++;
        if(j == t.size()){
            cout << i + 1 - t.size() << "\n";
            return;
        }
    }
    cout << "-1\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}