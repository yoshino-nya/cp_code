#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 20:03:23 
    string s, t;
    cin >> s >> t;
    set<char> st(t.begin(), t.end());
    for(int i = 1; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(st.count(s[i - 1]) == 0){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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