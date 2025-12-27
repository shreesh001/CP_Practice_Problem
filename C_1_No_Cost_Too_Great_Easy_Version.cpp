#include <bits/stdc++.h>
using namespace std;

// Simple sieve for primes up to 1e6
vector<int> primes;
vector<bool> isPrime(1000001, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1000000; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= 1000000; i++)
        if (isPrime[i]) primes.push_back(i);
}

// Function to get distinct prime factors
vector<int> getFactors(long long x) {
    vector<int> factors;
    for (int p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            factors.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) factors.push_back(x);
    return factors;
}

int main() {
    sieve(); // Precompute primes
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int nonOneA = 0;
        for (auto x : a) if (x > 1) nonOneA++;
        bool allBOne = true;
        for (auto x : b) if (x > 1) allBOne = false;
        // Case for output 2
        if ((nonOneA <= 1) && allBOne) {
            cout << 2 << "\n";
            continue;
        }

        // Check for repeated prime factors
        unordered_set<long long> used;
        bool ok = false;

        for (auto x : a) {
            if (x == 1) continue;
            vector<int> facs = getFactors(x);
            for (int f : facs) {
                if (used.count(f)) {
                    ok = true;
                    break;
                }
                used.insert(f);
            }
            if (ok) break;
        }

        if (!ok) {
            for (auto x : b) {
                if (x == 1) continue;
                vector<int> facs = getFactors(x);
                for (int f : facs) {
                    if (used.count(f)) {
                        ok = true;
                        break;
                    }
                    used.insert(f);
                }
                if (ok) break;
            }
        }

        cout << (ok ? 0 : 1) << "\n";
    }

    return 0;
}
