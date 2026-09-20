#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 12500;
constexpr int num = 119; // 每行放多少个，最多119

int b[num + 1];
set<pair<int, int>> st; // {lines, L}
int get(int x)
{
    int cnt = x / num;
    if(!cnt) return 0;
    return (N + cnt - 1) / cnt;
}
int ask(const vector<int> &a)
{
    cout << "? " << a.size() << " ";
    for(auto x : a)
        cout << x << " ";
    cout << endl;
    int res; cin >> res; return res;
}
void solve()
{
    int lines = ask(vector<int> (N, num));
    if(lines == 0){
        lines = ask(vector<int> (N, 1));
        cout << "! " << find(b + 1, b + num + 1, lines) - b << endl;
        return;
    }
    int L, R;
    auto it = st.lower_bound({lines, -1});
    L = it -> second;
    if(it == st.begin()) R = 8 * N;
    else R = prev(it) -> second;
    cerr << R << '\n';
    vector<int> s;
    for(int i = 1; i + L <= R; i++)
        s.push_back(i), s.push_back(L);
    lines = ask(s);
    cout << "! " << L + 2 * (R - L) - lines << endl;
}

int main()
{
    // freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    auto Insert = [&](int x, int y){
        auto it = st.lower_bound({x, -1});
        if(it == st.end() || it -> first != x){
            st.insert({x, y});
            // cerr << x << " " << y << '\n';
        }
    };
    for (int i = num; i <= 8 * N; i++)
        Insert(get(i), i);
    // for(auto [x, y] : st)
    //     cerr << x << " " << y << '\n';
    for(int i = 1; i <= num; i++)
        b[i] = (N + i - 1) / i;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}