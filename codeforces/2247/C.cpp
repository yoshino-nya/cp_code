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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        if(a == b) cout << "0\n";
        else {
            int cnt = 0, sum = 0, sum1 = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] == 1 && a[i] != b[i]) cnt++;
                sum += b[i];
                sum1 += a[i];
            }
            /*
            1 0 0 1
            0 1 1 0
            0 1 1 1
            */
            if(sum == n || sum1 == 0) cout << "-1\n";
            else if(cnt % 2 == 1) cout << "1\n";
            else cout << "2\n";
        }
    }
}