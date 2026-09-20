# [Codeforces Round 1049 (Div. 2)](https://codeforces.com/contest/2140)

## D

有 $n$ 个线段，第 $i$ 个线段是 $[l_i, r_i]$。初始时所有线段都未被标记。

可以重复进行以下的操作直到没有未被标记的线段:

1. 在第 $k$ 次操作中，如果有至少两个未被标记的线段，选择任意两个未被标记的线段 $[l_i,r_i]$ 和 $[l_j,r_j]$，标记这两个线段，然后可以增加一个新的线段 $[x_k, y_k]$ 满足以下条件：
   - $l_i \le x_k \le r_j$
   - $l_j \le y_k \le r_j$
   - $x_k \le y_k$
2. 如果只剩下一个未被标记的线段，标记它。

求最终最大的可能的所有被标记的线段的长度。一个线段 $([l, r])$ 的长度是 $r-l$。

### solution

> 昨晚没写出这题，甚至没有想很久。
>
> 但是我一开始也是想，如果 $n$ 为偶数应该会好写一点，但是倒也没想出来 $n$ 为偶数怎么搞。有点太懒了啊，这为啥不多思考一下呢？本来也想着就算知道 $n$ 为偶数怎么搞，奇数可能很不一样。
>
> 但事实上，如果知道 $n$ 为偶数怎么解决，奇数只需要改变一点点。

先考虑 $n$ 为偶数的情况，我们要做的实际上是把这 $n$ 个线段分成两个部分，使得 $\frac{n}{2}$ 个 $r$ 减去 $\frac{n}{2}$ 个 $l$ 的值尽量大。

看起来不是很好搞，但其实可以贪心解决，先令 $ans = \sum\limits_{i = 1}^{n}r_i$，问题就变成了我们需要减去 $\frac{n}{2}$ 个 $l_i + r_i$ 使得 $ans$ 最大，那么显然按 $l_i + r_i$ 排序，然后减去最小的 $\frac{n}{2}$ 个。

这样做，会不会出现后半部分的 $r$ 无法减去前半部分的 $l$ 呢？实际上并不会，因为如果无法减去，那么 $r_i < l_j$，这样的话 $l_i + r_i$ 肯定会小于 $l_j + r_j$，因为线段的中点是 $\frac{l + r}{2}$ 。

现在我们考虑 $n$ 为奇数的情况，实际上是类似的，因为去掉一个线段就变成偶数了。

### code

```cpp
void ChatGptDeepSeek()
{
    int n; cin >> n;
    vector<pii> seg(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        seg[i] = {l, r};
        ans += r - l + r;
    }
    sort(seg.begin(), seg.end(), [](pii x, pii y){
        return x.first + x.second < y.first + y.second;
    });
    ll sub = 0;
    for(int i = 0; i < n / 2; i++)
        sub += seg[i].first + seg[i].second;
    if(n % 2 == 0)
        cout << ans - sub << '\n';
    else{
        ll res = 0;
        for(int i = n / 2; i < n; i++)
            res = max(res, ans - seg[i].second - sub);
        int x = seg[n / 2].first + seg[n / 2].second;
        for(int i = 0; i < n / 2; i++){
            int y = seg[i].first + seg[i].second - seg[i].second;
            res = max(res, ans - sub - x + y);
        }
        cout << res << '\n';
    }
}
```

