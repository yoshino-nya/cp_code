#include <bits/stdc++.h>
using namespace std;

int main()
{
    system("g++ -std=c++20 gen.cpp -o gen");
    system("g++ -std=c++20 sol.cpp -o sol");
    system("g++ -std=c++20 std.cpp -o std");
    int t = 10000;
    for (int i = 1; i <= t; i++) {
        system("gen > 1.in");
        system("sol < 1.in > sol.out");
        system("std < 1.in > std.out");
        if (system("fc sol.out std.out")) {
            return 0;
        } else
            printf("running on test %d\n", i);
    }
    return 0;
}