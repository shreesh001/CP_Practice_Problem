#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = v.size();
        for(auto& i : v) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

int get_ans(int N, vector<int> P) {
    if (N <= 1) return 0;

    vector<int> primes;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p) is_prime[i] = false;
        }
    }
    for (int p = 2; p <= N; p++) {
        if (is_prime[p]) primes.push_back(p);
    }

    int p_max = primes.empty() ? 0 : primes.back();

    // 2. Impossibility Check: Verify elements beyond p_max are already sorted
    for (int i = p_max; i < N; ++i) {
        if (P[i] != i + 1) return -1;
    }

    // 3. Truncation: We only need to search the mutable prefix
    int effective_N = max(1, p_max);
    vector<int> start_state(P.begin(), P.begin() + effective_N);
    vector<int> target_state(effective_N);
    for (int i = 0; i < effective_N; ++i) {
        target_state[i] = i + 1;
    }

    if (start_state == target_state) return 0;

    // 4. Bidirectional BFS Setup
    unordered_map<vector<int>, int, VectorHash> dist_f, dist_b;
    queue<vector<int>> q_f, q_b;

    dist_f[start_state] = 0;
    q_f.push(start_state);

    dist_b[target_state] = 0;
    q_b.push(target_state);

    int shortest_path = -1;

    // 5. Level-by-Level Expansion
    while (!q_f.empty() && !q_b.empty()) {
        
        // Expand the smaller queue to minimize the branching factor
        if (q_f.size() <= q_b.size()) {
            int sz = q_f.size();
            while (sz--) { // Process exactly one level
                vector<int> curr = q_f.front();
                q_f.pop();
                int d = dist_f[curr];

                for (int p : primes) {
                    if (p > effective_N) break; // Don't reverse beyond our truncated size
                    
                    vector<int> nxt = curr;
                    reverse(nxt.begin(), nxt.begin() + p);
                    
                    // If the backward search has seen this state, we found an intersection!
                    if (dist_b.count(nxt)) {
                        int candidate = d + 1 + dist_b[nxt];
                        if (shortest_path == -1 || candidate < shortest_path) {
                            shortest_path = candidate;
                        }
                    }
                    
                    // If we haven't visited this state in the forward search, queue it
                    if (!dist_f.count(nxt)) {
                        dist_f[nxt] = d + 1;
                        q_f.push(nxt);
                    }
                }
            }
            if (shortest_path != -1) return shortest_path;
            
        } else {
            // Symmetrical logic for the backward queue
            int sz = q_b.size();
            while (sz--) {
                vector<int> curr = q_b.front();
                q_b.pop();
                int d = dist_b[curr];

                for (int p : primes) {
                    if (p > effective_N) break;
                    
                    vector<int> nxt = curr;
                    reverse(nxt.begin(), nxt.begin() + p);
                    
                    // If the forward search has seen this state, intersection found!
                    if (dist_f.count(nxt)) {
                        int candidate = d + 1 + dist_f[nxt];
                        if (shortest_path == -1 || candidate < shortest_path) {
                            shortest_path = candidate;
                        }
                    }
                    if (!dist_b.count(nxt)) {
                        dist_b[nxt] = d + 1;
                        q_b.push(nxt);
                    }
                }
            }
            if (shortest_path != -1) return shortest_path;
        }
    }

    // If queues exhaust and no path is found, it's impossible
    return -1;
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N;
    if (cin >> N) {
        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }
        cout << get_ans(N, P) << "\n";
    }
    return 0;
}