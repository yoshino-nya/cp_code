#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<char> res(n + 1, '1');
    auto ask = [&](int l, int r){
        cout << format("? {} ", abs(l - r) + 1);
        if(l <= r){
            for(int i = l; i <= r; i++)
                cout << i << " ";
        }else{
            for(int i = l; i >= r; i--)
                cout << i << " ";
        }
        cout << endl;
        int num; cin >> num;
        return num;
    };

    int cnt = ask(1, n);
    int idx1, idx2;
    if(cnt){
        int lo = 1, hi = n + 1;
        while(lo < hi - 1){
            int mid = (lo + hi) >> 1;
            if(ask(1, mid)) hi = mid;
            else lo = mid;
        }
        idx2 = hi, idx1 = idx2 - 1;
    }else{
        int lo = 0, hi = n;
        while(lo < hi - 1){
            int mid = (lo + hi) >> 1;
            if(ask(n, mid)) lo = mid;
            else hi = mid;
        }
        idx2 = lo, idx1 = idx2 + 1;
    }
    // cout << format("idx : {}, {}", idx1, idx2) << endl;
    cout << format("? 2 {} {}", idx1, idx2) << endl;
    cin >> cnt; assert(cnt);
    res[idx1] = '(', res[idx2] = ')';
    auto ask1 = [&](int x, int y) {
        cout << format("? 6 {} {} {} {} {} {}", x, idx2, idx1, y, idx1, y) << endl;
        /*
        x)(y(y
    )( 0
     () 6
    (( 1
    )) 3
        */ 
        cin >> cnt;
        assert((cnt == 0) || (cnt == 1) || (cnt == 3) || (cnt == 6));
        if(cnt == 0)
            res[x] = ')', res[y] = '(';
        else if(cnt == 1)
            res[x] = res[y] = '(';
        else if(cnt == 3)
            res[x] = res[y] = ')';
        else if(cnt == 6)
            res[x] = '(', res[y] = ')';
    };
    int x = 0;
    for(int i = 1; i <= n; i++){
        if(res[i] == '1'){
            if(!x) x = i;
            else{
                ask1(x, i);
                x = 0;
            }
        }
    }
    if(x){
        cout << format("? 2 {} {}", idx1, x) << endl;
        cin >> cnt;
        if(cnt) res[x] = ')';
        else res[x] = '(';
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        assert((res[i] == '(') || (res[i] ==')'));
        cout << res[i];
    }
    cout << endl;
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
()
((
))
)(
(( x )(

x)( y(y
() 5
(( 1
)) 3
)( 0 一次可以确定两个了

(((()
()((((
*/
