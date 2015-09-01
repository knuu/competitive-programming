ll powmod(ll n, ll k, ll mod) {
  if (k == 0) {
    return 1;
  } else if (k % 2 == 0) {
    return powmod(n * n, k / 2, mod) % mod;
  } else {
    return (n * powmod(n, k-1, mod)) % mod;
  }
}

ll inv(ll x, ll mod) {
  return powmod(x, x-2, mod);
}

ll comb(ll n, ll k) {
  assert (0 <= k && k <= n);
  ll ret = 1;
  REP(i, k) {
    ret *= n - i;
    ret %= mod;
    ret *= inv(i+1);
    ret %= mod;
  }
  return ret;
}
