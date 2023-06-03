using vl = vector<ll>;

vl primes;
const int N=10001;  

bool esPrimo[N];
void sieve(ll n) {// O(n * sqrt(n))
    memset(esPrimo, true, sizeof(esPrimo));
    esPrimo[0] = esPrimo[1] = 0;
    for (ll p = 2; p < n; p++) {
        if (esPrimo[p]) {
            for (ll i = p * p; i < n; i += p)
                esPrimo[i] = 0;
            primes.push_back(p);
        }
    }
}

// O(sqrt(n))
bool isPrime(ll n) {
    for (ll i = 0; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Sin calcular primos en O(sqrt(n))
vl primeFactors(ll n) {
    vl factors;
    ll idx = 2;
    while (n != 1) {
        while (n % idx == 0) {
            n /= idx;
            factors.push_back(idx);
        }
        idx++;
    }
    return factors;
}

// Contar el numero de factores primos del entero N
int numPF(ll n) {
    int ans = 0;
    for (int i = 0; (i < (int)primes.size()) && (primes[i] * primes[i] <= n); ++i)
        while (n % primes[i] == 0) {
            n /= primes[i];
            ans++;
        }
    return ans + (n != 1);
}
