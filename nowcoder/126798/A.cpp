#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    set<int> st;
    st.insert(a + b);
    st.insert(a - b);
    st.insert(a * b);
    if(a % b == 0) st.insert(a / b);
    if(st.contains(c)) printf("YES\n");
    else printf("NO\n");
}