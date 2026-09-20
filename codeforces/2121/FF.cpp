#include<bits/stdc++.h>
using namespace std;

#define test solve()
#define testm int T; cin >> T; while(T--) solve()

#define rep(i, k, n) for(int i = (k); i <= (n); i++) 
#define srep(i, k, n) for(int i = (k); i >= (n); i--)
#define ump unordered_map
#define ust unordered_set
#define ms(a, b) memset(a, (b), sizeof(a))
using ll = long long;
using pii = pair<int, int>;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define quit(x) {cout << (x) << endl; return;}
void solve() {
    int n, x;
    ll s;
    cin >> n >> s >> x;
    vector<int> arr(n + 1);
    rep(i, 1, n)
        cin >> arr[i];
    map<ll, int> px, pxp;
    px[0] = 1;
    ll cur = 0;
    ll ans = 0;
    bool cx = false;
    rep(i, 1, n) {
        if(arr[i] > x) {
            px.clear();
            pxp.clear();
            px[0] = 1;
            cur = 0;
            cx = false;
            continue;
        }
        cur += arr[i];
        if(arr[i] == x) {
            cx = true;
            for(auto [a, b]: pxp)
                px[a] += b;
            pxp.clear();
        }
        pxp[cur]++;
        if(cx) {
            if(px.contains(cur - s))
                ans += px[cur - s];
        }
    }
    cout << ans << endl;
}

int main() {
    IOS;
    testm;
}