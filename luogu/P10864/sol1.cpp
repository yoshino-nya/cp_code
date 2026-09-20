// Date: 2025-03-18
// Time: 17:44:48

// #include <bits/stdc++.h>
#include "C:/usr/codes/cp/template/debug.hpp"

using namespace std;

void ChatGptDeepSeek()
{
    set<pair<int, int>> st { { 1, 2 }, { 1, 1 } };
    st.erase({ 1, 2 });
    st.erase({ 1, 1 });
    st.erase({ 1, 1 });
    st.erase({ 1, 1 });
    st.erase({ 1, 1 });
    st.erase({ 1, 1 });
    st.erase({ 1, 1 });
    for(auto x:st) cout<<"Yuan\n";
    dbg(st);
    cout<<st.size()<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}