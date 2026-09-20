// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

struct node{
    int dis, i, j, sw;
};
int dis[666][666][2];
void ChatGptDeepSeek() // Date: 2025-08-24
{                      // Time: 20:14:45 
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
        cin >> s[i];
    auto cmp = [&](node x, node y){
        return x.dis > y.dis;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    int px = -1, py = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            dis[i][j][0] = dis[i][j][1] = INF;
            if(s[i][j] == 'S'){
                dis[i][j][0] = 0;
                pq.push({0, i, j, 0});
            }
            if(s[i][j] == 'G')
                px = i, py = j;
        }
    vector<pii> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    while(pq.size()){
        auto [dist, i, j, sw] = pq.top(); pq.pop();
        // cerr << dist << " " << i << " " << j << '\n';
        // if(s[i][j] == 'G'){
        //     cout << dist << '\n';
        //     return;
        // }
        // if(dist > dis[i][j][sw]) continue;
        for(auto [dx, dy] : dir){
            int nx = i + dx, ny = j + dy;
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || (s[nx][ny] == '#')) continue;
            if(s[nx][ny] == '?'){
                if(dis[nx][ny][sw ^ 1] > dist + 1){
                    dis[nx][ny][sw ^ 1] = dist + 1;
                    pq.push({dist + 1, nx, ny, sw ^ 1});
                }
            }
            else if(s[nx][ny] == 'o'){
                
                if(sw == 0 && dis[nx][ny][sw] > dist + 1){
                    dis[nx][ny][sw] = dist + 1;
                    pq.push({dist + 1, nx, ny, sw});
                }
            }
            else if(s[nx][ny] == 'x'){
                if(sw == 1 && dis[nx][ny][sw] > dist + 1){
                    dis[nx][ny][sw] = dist + 1;
                    pq.push({dist + 1, nx, ny, sw});
                }
            }
            else{
                if(dis[nx][ny][sw] > dist + 1){
                    dis[nx][ny][sw] = dist + 1;
                    pq.push({dist + 1, nx, ny, sw});
                }
            }
        }
    }
    assert(px != -1);
    if(min(dis[px][py][0], dis[px][py][1]) == INF)
        cout << "-1\n";
    else
        cout << min(dis[px][py][0], dis[px][py][1]) << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}