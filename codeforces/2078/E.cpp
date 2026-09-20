/*
x+y = ..
| 相当于就是给这个表达式加上一些东西
看答案加了多少 就可以知道 x 和 y ，这一位有几个1
*/
// Date: 2025-03-11
// Time: 14:39:57

#include <bits/stdc++.h>
using namespace std;

constexpr int val = 715827882;

int ask(int n)
{
    cout << n << endl;
    int res;
    cin >> res;
    return res;
}
void ChatGptDeepSeek()
{
    // 问01010101非常有道理啊
    // 因为这一位的1，一定会比后面所有的和要大

    // 不对，，，但是怎么和10101010结合起来呢？
    // 直接问 0 和 0101010101吧
    //
    int sum = ask(0);
    int res = ask(val);
    vector<int> b(30);
    int x = res - sum, y = 0;
    for (int i = 29; i >= 0; i -= 2) {
        if (x >= (1 << (i + 1))) {
            // b[i] = 2;
            x -= 1 << (i + 1);
        } else if (x >= (1 << i)) {
            b[i] = 1;
            x -= 1 << i;
            y += 1 << i;
        } else {
            y += 1 << (i + 1);
            b[i] = 2;
        }
    }
    assert(x == 0);
    x = sum - y;
    for (int i = 28; i >= 0; i -= 2) {
        if (x >= (1 << (i + 1))) {
            x -= 1 << (i + 1);
            b[i] = 2;
        } else if (x >= (1 << i)) {
            x -= 1 << i;
            b[i] = 1;
        }
    }
    cout << "!" << endl;
    int m;
    cin >> m;
    for (int i = 29; i >= 0; i--) {
        // cerr << b[i] << " \n";
        if (m >> i & 1) {
            sum += (2 - b[i]) * (1 << i);
        }
    }
    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int sum=0;
    // for(int i=29;i>=0;i--){
    //     if(i&1) sum|=1<<i;
    // }
    // cerr<<sum<<'\n';
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}