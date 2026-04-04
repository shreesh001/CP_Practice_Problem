#include <bits/stdc++.h>
using namespace std;

long MaxScore(int N, int D, int K, int P, vector<vector<int>> Films) {
    vector<vector<long long>> adj(K + 1);
    for(int i = 0; i < N; ++i) {
        adj[Films[i][0]].push_back(Films[i][1]);
    }
    
    vector<vector<long long>> best(K + 1);
    for(int g = 1; g <= K; ++g) {
        sort(adj[g].rbegin(), adj[g].rend());
        best[g].assign(adj[g].size() + 1, 0);
        for(size_t i = 0; i < adj[g].size(); ++i) {
            best[g][i + 1] = best[g][i] + adj[g][i];
        }
    }
    
    vector<pair<long long, int>> all_films;
    for(int i = 0; i < N; ++i) {
        all_films.push_back({Films[i][1], Films[i][0]});
    }
    sort(all_films.rbegin(), all_films.rend());
    
    int limit = (D + 1) / 2;
    
    vector<long long> dp(D + 1, -1e18);
    dp[0] = 0;
    
    for(int g = 1; g <= K; ++g) {
        vector<long long> next_dp(D + 1, -1e18);
        for(int j = 0; j <= D; ++j) {
            if(dp[j] <= -1e17) continue;
            
            int max_c = min((int)best[g].size() - 1, limit);
            for(int c = 0; c <= max_c; ++c) {
                if(j + c <= D) {
                    next_dp[j + c] = max(next_dp[j + c], dp[j] + best[g][c]);
                }
            }
        }
        dp = next_dp;
    }
    
    long long ans = dp[D];
    
    for(int g = 1; g <= K; ++g) {
        int max_possible = best[g].size() - 1;
        if(max_possible <= limit) continue;
        
        vector<long long> pref_others;
        pref_others.push_back(0);
        for(auto& film : all_films) {
            if(film.second != g) {
                pref_others.push_back(pref_others.back() + film.first);
            }
            if(pref_others.size() > limit + 1) break;
        }
        
        for(int c = limit + 1; c <= min(D, max_possible); ++c) {
            int needed = D - c;
            
            if(needed < pref_others.size()) {
                long long penalty = (long long)(2 * c - D - 1) * P;
                long long score = best[g][c] + pref_others[needed] - penalty;
                ans = max(ans, score);
            }
        }
    }
    
    return (long)ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, D, K, P;
    
    if (!(cin >> N >> D >> K >> P)) return 0;
    
    vector<vector<int>> Films(N, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        cin >> Films[i][0] >> Films[i][1];
    }
    
    long result = MaxScore(N, D, K, P, Films);
    
    cout << result << "\n";
    
    return 0;
}