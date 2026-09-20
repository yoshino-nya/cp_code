#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<char>> vec(n + 1, vector<char> (n + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> vec[i][j];
    set<string> st;
    for(int i = 1; i + m - 1 <= n; i++)
        for(int  j = 1; j + m - 1 <= n; j++){
            string tmp;
            for(int k = i; k <= i + m - 1; k++)
                for(int l = j; l <= j + m - 1; l++)
                    tmp += vec[k][l];
            assert(tmp.size() == m * m);
            st.insert(tmp);
        }
    cout << st.size() << '\n';
}