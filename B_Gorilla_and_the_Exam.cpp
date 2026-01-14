#include <bits/stdc++.h>

int main() {
    int tt;
    std::cin >> tt;
    while (tt--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    std::vector<int> cnt = {1};
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cnt.back()++;
        } else {
            cnt.emplace_back(1);
        }
    }
    int flag=0;
    std::sort(cnt.begin(), cnt.end());
    int m = cnt.size();
    for (int i = 0; i < m - 1; i++) {
        if (cnt[i] > k) {
            std::cout << m - i << "\n";
            flag=1;
            break;
        }
        k -= cnt[i];
    }
    if (flag==1) continue;
    std::cout << 1 << "\n";
    }
}

