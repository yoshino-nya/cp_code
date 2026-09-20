// Date: 2025-03-30
// Time: 19:03:53
#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) { return (x) & (-x); }
void ChatGptDeepSeek()
{
    /*
    x|y = x
    x^y ^x
    */
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 1)
    {
        if (x != y)
            cout << "NO\n";
        else
            cout << "YES\n"
                 << x << '\n';
        return;
    }
    if (x == y)
    {
        if (n & 1)
        {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
                cout << x << ' ';
            cout << '\n';
            return;
        }
        if (x == (1 << __lg(x)))
        {
            cout << "NO\n";
            return;
        }
        int A = x - (1 << __lg(x));
        cout << "YES\n";
        cout << A << " " << (1 << __lg(x)) << " ";
        for (int i = 1; i <= n - 2; i++)
            cout << x << " ";
        cout << '\n';
        return;
    }
    int A = 0, B = 0;
    for (int i = 30; i >= 0; i--)
    {
        // y ^, x |
        int X = x >> i & 1, Y = y >> i & 1;
        if (X == 0 && Y == 1)
        {
            cout << "NO\n";
            return;
        }
        if (X == 1 && Y == 0)
        {
            A |= (1 << i);
            B |= (1 << i);
        }
        else if (Y == 1 && X == 1)
        { // 若x=y 且二进制只有一位 才会A 或 B等于0
            A |= (1 << i);
        }
    }
    /* A^B ? */
    if (n == 3)
    {
        cout << "YES\n";
        if (x == y)
            cout << x << " " << x << " " << x << '\n';
        else
        {
            int Z = 0;
            for (int i = 30; i >= 0; i--)
            {
                int X = x >> i & 1, Y = y >> i & 1;
                if (X == 1 && Y == 0)
                {
                    if (A != (1 << i))
                    {
                        A -= (1 << i);
                        // cout << "YES\n"
                        //      << A << " " << B << " " << (1 << i) << '\n';
                        Z = 1 << i;
                        break;
                    }
                    if (B != (1 << i))
                    {
                        B -= (1 << i);
                        Z = 1 << i;
                        break;
                    }
                }
                else if (Y == 1 && X == 1)
                { // 若x=y 且二进制只有一位 才会A 或 B等于0
                    A |= (1 << i);
                    if (A != (1 << i))
                    {
                        A -= (1 << i);
                        Z = 1 << i;
                        break;
                    }
                }
            }
            cout << "NO\n";
        }
        return;
    }
    assert((A | B) == x);
    assert((A ^ B) == y);
    assert(B);
    if (A == 0 || B == 0)
    {
        /* 仅有x==y时？ */
        if (n & 1)
        {
            A = max(A, B);
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
                cout << A << ' ';
            cout << '\n';
        }
        else
            cout << "NO\n";
        return;
    }
    if (n % 2 == 0)
    {
        cout << "YES\n"
             << A << " " << B << '\n';
        for (int i = 1; i <= n - 2; i++)
            cout << (1 << __lg(A)) << ' ';
        cout << '\n';
    } // A^B ^A^B ^A ^B
    else
    {
        
        int Z = 0;
        for (int i = 30; i >= 0; i--)
        {
            int X = x >> i & 1, Y = y >> i & 1;
            if (X == 1 && Y == 0)
            {
                if (A != (1 << i))
                {
                    A -= (1 << i);
                    // cout << "YES\n"
                    //      << A << " " << B << " " << (1 << i) << '\n';
                    Z = 1 << i;
                    break;
                }
                if (B != (1 << i))
                {
                    B -= (1 << i);
                    Z = 1 << i;
                    break;
                }
            }
            else if (Y == 1 && X == 1)
            { // 若x=y 且二进制只有一位 才会A 或 B等于0
                A |= (1 << i);
                if (A != (1 << i))
                {
                    A -= (1 << i);
                    Z = 1 << i;
                    break;
                }
            }
        }
        if(Z){
            cout<<"YES\n"<<A<<" "<<B<<" "<<Z<<" ";
            for(int i=1;i<=n-3;i++) cout<<A<<" ";
            cout<<'\n';
        }else cout<<"NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}