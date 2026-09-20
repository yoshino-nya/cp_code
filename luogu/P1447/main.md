---
date: 2026-09-20 09:57:28
---

每个点 $(x, y)$ 的贡献是 $2 \cdot \gcd(x, y) - 1$

所以答案就是 $\sum\limits_{i}^{n}\sum\limits_{j}^{m}(2\cdot \gcd(i,j) - 1)$

$\gcd(i, j) \mid x$ 的 pair 的数量为 $\lfloor \frac{n}{x} \rfloor \cdot \lfloor \frac{m}{x} \rfloor$，减去 $x$ 的倍数的 pairs 就可以得到 $\gcd(i,j) = x$ 的数量。

复杂度是 $\sum\limits_{i}^{n}\frac{n}{i}$，大概是 $\mathcal{O}(n \log{n})$ 的复杂度。