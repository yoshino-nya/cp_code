#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c, d, f;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(2);
    int num = 0;
    for (double i = -100.00; i <= 100.00; i += 0.001)
    {
        double e = i;
        f = e + 0.001;
        if ((a * e * e * e + b * e * e + c * e + d) * (a * f * f * f + b * f * f + c * f + d) < 0)
        {
            cout << i << " ";
            num++;
        }
        if (num == 3)
        {
            break;
        }
    }

    return 0;
}