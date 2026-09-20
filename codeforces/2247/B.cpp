#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, k, m;
        cin >> n >> k >> m;
        if(m < k) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < k - 1; i++)
                cout << "1 ";
            cout << m - k + 1;
            for(int i = 0; i < n - k; i++)
                cout << " 1";
            cout << "\n";
        }
    }
}