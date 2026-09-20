#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool check(string s){
    int cnt = 0;
    vector<int> st(s.size());
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') cnt++;
        else{
            if(cnt == 1){
                cnt = 0;
                if(i == 1) continue;
                if(i - 3 >= 0 && s[i - 3] == '0' && !st[i - 3]) continue;
                if(i + 1 < s.size() && s[i + 1] == '0'){
                    st[i + 1] = 1;
                    continue;
                }
                return false;
            }
            cnt = 0;
        }
    }
    return true;
}
void solve()
{
    int n; string s;
    cin >> n >> s;
    bool ans = check(s);
    cout << (ans ? "YES" : "NO") << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}