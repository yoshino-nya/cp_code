#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;

constexpr int N = 300050;
struct BIT{
    LL bit[N];
    int lowbit(int x){return (x) & (-x);}
    void add(int i, int x)
    {
        while(i < N){
            bit[i] += x;
            i += lowbit(i);
        }
    }
    LL query(int i)
    {
        i = min(N - 1, i);
        LL res = 0;
        while(i){
            res += bit[i];
            i -= lowbit(i);
        }
        return res;
    }
}t1, t2;
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<LL> p(n + 1);
    LL sum = 0;
    for(int i = 1; i <= n; i++){
        p[i] += p[i - 1] + sum;
        for(LL k = 1; k * a[i] < N; k++){
            p[i] -= (t1.query((k + 1) * a[i] - 1) - t1.query(k * a[i] - 1)) * k * a[i];
        }
        t1.add(a[i], 1);
        // a[i] - (a[i] / a[j]) * a[j]
        for(LL k = 1; k * a[i] < N; k++)
            t2.add(k * a[i], a[i]);
        p[i] += 1LL * i * a[i] - t2.query(a[i]);
        sum += a[i];
        cout << p[i] << " \n" [i == n];
    }
}