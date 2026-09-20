#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = int(1e5);

int get(int x)
{
    return (N + x - 1) / x;
}
int a[N + 1];
void solve()
{
    cout << "? " << N; for(int i = 1; i <= N; i++) cout << " 1"; cout << endl;
    int lines; cin >> lines;
    if(lines == 1){
        cout << "! " << N << endl;
        return;
    }
    if(!a[lines - 1]){
        cout << "! " << a[lines] << '\n';
        return;
    }
    // int num = get(lines);
    int L = a[lines], R = a[lines - 1] - 1;
    // cerr << L << " " << R << '\n';
    if(L == R){
        cout << "! " << L << endl;
        return;
    }
    // L - 1 + 1? + 2?
    cout << "? " << 2 * (R - L + 1) << " ";
    for(int x = 1; L - 1 + x <= R; x++){
        cout << x << " " << L - 1 <<  " ";
    }
    cout << endl;
    cin >> lines;
    cout << "! " << 2 * (R - L + 1) - lines + L - 1 << endl;
}

int main()
{
    // freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 1; i <= N; i++)
    {
        if (!a[get(i)])
        {
            cerr << i << '\n';
            a[get(i)] = i;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}