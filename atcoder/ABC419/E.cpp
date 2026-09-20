#include<bits/stdc++.h>
using namespace std;

int dp1[505][505];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n + 1), d(l + 1), p(m, 0);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= l; i++){
        for(int x = 0; x < m; x++){
            int now = 0;
            for(int j = i; j <= n; j += l){
                if(a[j] <= x) now += x - a[j];
                else now += x + m - a[j];
            }
            dp1[i][x] = now;
        }
    }
    for(int x = 0; x < m; x++)
        p[x] = dp1[1][x];
    // for(int j = 0; j < m; j++)
    //         cerr << p[j] << " \n"[j + 1 == m];
    for(int i = 2; i <= l; i++){
        vector<int> np(p), p1(m, INT_MAX);
        for(int x = 0; x < m; x++)
            p[x] = p[x] + dp1[i][0];
        for(int x = 0; x < m; x++){
            for(int j = 0; j < m; j++){
                p1[(x + j) % m] = min(p1[(x + j) % m], min(p[(x + j) % m], np[x] + dp1[i][j]));
            }
        }
        // cerr << "*********dp : \n";
        // for(int j = 0; j < m; j++)
        //     cerr << dp1[i][j] << " \n"[j + 1 == m];
        // cerr << "********* \n";

        p = p1;
        // for(int j = 0; j < m; j++)
        //     cerr << p[j] << " \n"[j + 1 == m];
    }
    cout << p[0] << '\n';
    return 0;
}