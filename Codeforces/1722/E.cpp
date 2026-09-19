#include <print>
#include <cstdio>

constexpr int N = 1'000;
long long sum[N + 1][N + 1];
void solve()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        int h, w;
        scanf("%d%d", &h, &w);
        sum[h][w] += h * w;
    }
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            sum[i][j] += sum[i][j - 1];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            sum[j][i] += sum[j - 1][i];
    
    auto query = [&](int hl, int wl, int hr, int wr) {
        long long res = sum[hr][wr] - sum[hr][wl - 1] - sum[hl - 1][wr] + sum[hl - 1][wl - 1];
        return res;
    };

    while(q--) {
        int hl, wl, hr, wr;
        scanf("%d%d%d%d", &hl, &wl, &hr, &wr);
        hl += 1, wl += 1, hr -= 1, wr -= 1;
        if(hl > hr || wl > wr) {
            std::println("0");
            continue;
        }
        std::println("{}", query(hl, wl, hr, wr));
    }
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            sum[i][j] = 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
}