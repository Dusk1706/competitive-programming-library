// La exponenciación modular (x^n mod m) se puede hacer en complejidad O (log n).

int modpow(int x, int n, int m) {
  if (n == 0)
    return 1;
  int u = modpow(x, n/2, m);
  u = (u * u) % m;
  if (n % 2 == 1)
    u = (u * x) % m;
  return u;
}
