---
date: 2026-09-20 11:30:08
---

$$\sum\limits_{i}^{n} \sum\limits_{j}^{m} [\gcd(i, j) \in primes]$$

$$
\sum\limits_{p \in primes} \sum\limits_{i}^{n} \sum\limits_{j}^{m} [\gcd(i, j) = p]
$$

$$
\sum\limits_{p \in primes} \sum\limits_{i}^{\frac{n}{p}} \sum\limits_{j}^{\frac{m}{p}} [\gcd(i, j) = 1]
$$

$$
\sum\limits_{p \in primes} \sum\limits_{i}^{\frac{n}{p}} \sum\limits_{j}^{\frac{m}{p}} \sum\limits_{d | \gcd(i, j)} \mu(d)
$$

枚举 d

$$
\sum\limits_{d=1}^{\frac{n}{p}} \mu(d) \sum\limits_{p \in primes} \sum\limits_{i}^{\frac{n}{p}} \sum\limits_{j}^{\frac{m}{p}} [d | \gcd(i, j)]
$$

$$
\sum\limits_{d=1}^{\frac{n}{p}} \sum\limits_{p \in primes} \mu(d) \lfloor \frac{n}{pd} \rfloor \lfloor \frac{m}{pd} \rfloor 
$$

$k = pd$

$$
\sum\limits_{d=1}^{\frac{n}{p}} \sum\limits_{p \in primes} \mu(\frac{k}{p}) \lfloor \frac{n}{k} \rfloor \lfloor \frac{m}{k} \rfloor 
$$

枚举 k

$$
\sum\limits_{k=1}^{n} \sum\limits_{p \in primes,p \mid k} \mu(\frac{k}{p}) \lfloor \frac{n}{k} \rfloor \lfloor \frac{m}{k} \rfloor 
$$

$$
f(x) = \sum\limits_{p \in primes,p\mid x} \mu(\frac{x}{p}) 
$$