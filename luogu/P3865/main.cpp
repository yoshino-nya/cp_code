#include<bits/stdc++.h>
using namespace std;

struct ST{
    vector<int> LOG2;
    vector<vector<int>> info;

    int op(int x, int y){
        return max(x, y);
    }
    ST(vector<int> &vec){
        // 1-index 
        int n = vec.size() - 1;
        LOG2.assign(n + 1, 0);
        // LOG2[1] = 0;
        for(int i = 2; i <= n; i++)
            LOG2[i] = LOG2[i >> 1] + 1;
        info.assign(n + 1, vector<int> (LOG2[n] + 1, 0));
        for(int i = 1; i <= n; i++){
            info[i][0] = vec[i];
        }
        for(int k = 1; k <= LOG2[n]; k++){
            for(int i = 1; i + (1 << k) <= n + 1; i++){
                info[i][k] = op(info[i][k - 1], info[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int query(int l, int r){
        int k = LOG2[r - l + 1];
        return op(info[l][k], info[r - (1 << k) + 1][k]);
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    ST st(a);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
    }
    return 0;
}