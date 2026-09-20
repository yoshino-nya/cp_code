#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<vector<int>> vec(5, vector<int>(5));
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            scanf("%d", &vec[i][j]);
    for (int i = 1; i <= 4; i++)
    {
        set<int> st;
        for (int j = 1; j <= 4; j++)
            st.insert(vec[i][j]);
        if (st.size() != 4)
        {
            printf("NO\n");
            return;
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        set<int> st;
        for (int j = 1; j <= 4; j++)
            st.insert(vec[j][i]);
        if (st.size() != 4)
        {
            printf("NO\n");
            return;
        }
    }
    for (int i = 1; i <= 4; i += 2)
    {
        for (int j = 1; j <= 4; j += 2)
        {
            set<int> st;
            st.insert(vec[i][j]);
            st.insert(vec[i + 1][j]);
            st.insert(vec[i][j + 1]);
            st.insert(vec[i + 1][j + 1]);
            if (st.size() != 4)
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}