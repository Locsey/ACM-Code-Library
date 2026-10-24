#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

constexpr ll MOD = 998244353;

ll G(ll x) {
    return 4 * x - 2LL * __builtin_popcountll(x);
}

ll H(ll x) {
    ll res = 4 * x;
    for (int i = 0; i < 61; ++i) {
        if ((x >> i) & 1LL) {
            res += i + 1;
        }
    }
    return res;
}

ll solve(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    ll l = 0, r = n;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (G(mid) >= n - 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    ll R = l;
    ll ans = H(R);

    ll first = (R + 15) / 16 * 16;
    for (ll x = first; x <= R + 457; x += 16) {
        ans = min(ans, H(x));
    }

    return ans - n;
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        ll l, r;
        cin >> l >> r;

        ll ans = 0;
        for (ll n = l; n <= r; ++n) {
            ans = (ans + solve(n)) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}