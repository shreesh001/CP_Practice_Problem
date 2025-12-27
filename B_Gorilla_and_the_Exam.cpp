#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        unordered_map<long long, long long> freq;
        for (auto &x : a) freq[x]++;

        set<pair<long long,long long>> st; // {frequency, value}
        for (auto &el : freq) st.insert({el.second, el.first});

        if (k == n) {     // your custom rule
            cout << 1 << "\n";
            continue;
        }

        while (k > 0 && !st.empty()) {
            auto it = st.begin();
            long long f = it->first;

            if (f > k) break;

            k -= f;
            st.erase(it);
        }

        cout << st.size() << "\n";
    }
}
