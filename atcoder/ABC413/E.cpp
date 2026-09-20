// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 20:44:54
vector<int> get1(vector<int> &a, int s)
{
    if(s == 1)
        return a;
    vector<int> v1 (a.begin(), a.begin() + s / 2);
    vector<int> v2 (a.begin() + s / 2, a.end());
    v1 = get1(v1, s >> 1);
    v2 = get1(v2, s >> 1);
    if(v1[0] < v2[0]){
        for(auto x : v2)
            v1.push_back(x);
        return v1;
    }else{
        for(auto x : v1)
            v2.push_back(x);
        return v2;
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> p(1 << n);
    for(auto &i : p) cin >> i;
    vector res = get1(p, 1 << n);
    for(auto x : res)
        cout << x << " ";
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}