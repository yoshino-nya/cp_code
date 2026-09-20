// Date: 2025-03-11
// Time: 23:23:17

#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b, int c)
{
    cout << "? " << a << " " << b << " " << c << endl;
    int x;
    cin >> x;
    return x;
}
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    int x = 1, y = 2, z = 3;
    for (int i = 1; i <= 75; i++) {
        int X=ask(x,y,z);
        if(!X){
            cout<<"! "<<x<<" "<<y<<" "<<z<<endl;
            return;
        }
        int Y=rand();
        if(Y%3==0) x=X;
        else if(Y%3==1) y=X;
        else z=X;
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