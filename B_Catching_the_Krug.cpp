#include <bits/stdc++.h>
using namespace std;

int MaxCrates(int N, int M, vector<int>& W, vector<int>& K) {
    sort(W.begin(), W.end());
    sort(K.begin(), K.end());

    int low = 0;
    int high = min(N, M);
    int best = 0;

    auto canLoad = [&](int k) {
        if (k == 0) return true;
        
        vector<int> combined(k);

        for (int i = 0; i < k; ++i) {
            int crate_weight = W[k - 1 - i]; 
            int bag_weight = i;              
            combined[i] = crate_weight + bag_weight;
        }

        sort(combined.begin(), combined.end());
        
        for (int i = 0; i < k; ++i) {
            int pallet_capacity = K[M - k + i];
            if (combined[i] > pallet_capacity) {
                return false;
            }
        }
        
        return true;
    };
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canLoad(mid)) {
            best = mid;    
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }

    return best;
}

int main() {
    // Fast I/O for competitive programming
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }
    
    vector<int> K(M);
    for (int i = 0; i < M; ++i) {
        cin >> K[i];
    }
    
    cout << MaxCrates(N, M, W, K) << "\n";
    return 0;
}