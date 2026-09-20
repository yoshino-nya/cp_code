// Date: 2025-03-23
// Time: 13:55:27
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int dis, x, y;
    friend bool operator<(const node a, const node b)
    {
        if (a.dis == b.dis)
        {
            if (a.x == b.x)
                return a.y < b.y;
            return a.x < b.x;
        }
        return a.dis < b.dis;
    };
    friend bool operator>(const node a, const node b)
    {
        if (a.dis == b.dis)
        {
            if (a.x == b.x)
                return a.y > b.y;
            return a.x > b.x;
        }
        return a.dis > b.dis;
    };
};
void ChatGptDeepSeek()
{
    int n;
    cin >> n;

    priority_queue<node, vector<node>, greater<>> q1; // 无人的
    priority_queue<node, vector<node>, greater<>> q2; // 有人的

    int m = 2 * sqrt(n);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
        {
            q1.push({3 * i + 3 * j + 2, 3 * i + 1, 3 * j + 1});
        }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        // cerr << q1.top().dis << " " << q1.top().x << " " << q1.top().y << '\n';
        // if (q2.size())
        //     cerr << "q2 " << q2.top().dis << " " << q2.top().x << " " << q2.top().y << '\n';

        if (q2.empty() || q2.top() > q1.top() || t == 0)
        {
            auto [dis, x, y] = q1.top();
            q1.pop();
            cout << x << " " << y << '\n';
            q2.push({dis + 1, x + 1, y});
            q2.push({dis + 1, x, y + 1});
            q2.push({dis + 4, x + 1, y + 1});
        }
        else
        {
            cout << q2.top().x << " " << q2.top().y << '\n';
            q2.pop();
        }
    }
    /*
    3x+2,3y+2 需要多走两步
    其余的步数全是横坐标+纵坐标的
    */
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