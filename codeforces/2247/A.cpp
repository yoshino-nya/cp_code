#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    /*
    1 -1 1 -1
    1 1 1 1
    1 -1 -1 1
    1 -1 1 -1
    */
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        if(n & 1) cout << "NO\n";
        else {
            auto work = [&](int i) {
                a[i] = -a[i];
                a[i + 1] = -a[i + 1];
            };
            for(int i = 0; i + 1 < n; i++) {
                if(i % 2 == 0 && a[i] != 1) work(i);
                else if(i % 2 == 1 && a[i] != -1) work(i);
            }
            if(a[n - 1] != -1) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}