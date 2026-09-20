#include <bits/stdc++.h>
using namespace std;

void Codeforces()
{
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1), order(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> p[i], order[p[i]] = i;
    vector<int> P(p);
    set<int> st;
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        if(order[k] > r || order[k] < l){
            cout << "-1 ";
            continue;
        }
        
        int cnt = 0, L = 0, R = 0, Lx = 0, Rx = 0;
        bool find = false;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(order[k] == mid){
                find = true;
                break;
            }
            if(order[k] < mid){
                if(P[mid] < k){
                    if(P[mid] != p[mid]){
                        cnt = -1;
                        break;
                    }else{
                        cnt++;
                        P[mid] = k + 1;
                        st.insert(mid);
                        Rx++;
                    }
                }
                R++;
                r = mid - 1;
            }else{
                if(P[mid] > k){
                    if(P[mid] != p[mid]){
                        cnt = -1;
                        break;
                    }else{
                        cnt++;
                        P[mid] = k - 1;
                        st.insert(mid);
                        Lx++;
                    }
                }
                L++;
                l = mid + 1;
            }
        }
        if(k <= L || R > n - k) find = false;
        // cout << (find ? 2 * cnt : -1) << " ";
        if(find){
            if(Lx < Rx) swap(Lx, Rx);
            cout << Lx + Rx + Lx - Rx << " ";
        }else{
            cout << "-1 ";
        }
        for(auto x : st)
            P[x] = p[x];
        st.clear();
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        Codeforces();
}