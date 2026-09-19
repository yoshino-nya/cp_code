/*
date: 2026-09-20 00:31:43
path: ~/Projects/cp_code/Luogu/P2158/main_1.cpp
*/

#include<print>
#include<cstdio>
#include<vector>

constexpr int N = 40'000;
int phi[N + 1];
bool vis[N + 1];
std::vector<int> primes;

int main()
{
    phi[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(!vis[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for(int p : primes) {
            if(i * p > N) break;
            vis[i * p] = true;

            if(i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
    int n; scanf("%d", &n);
    if(n == 1) {
        std::println("0");
        return 0;
    }
    int res = 0;
    for(int i = 1; i < n; i++){
        res += phi[i];
    }
    std::println("{}", res * 2 + 1);
}