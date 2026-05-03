#include <bits/stdc++.h>
using namespace std;

// 1. Corrected BFS function
bool isconnected(int n, const vector<int>& a) {
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        int u = i + 1;      // Current index (1-based)
        int v = a[i];       // Value pointing to
        
        // FIX: Add bidirectional edges
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS initialization
    vector<int> vis(n + 1, 0);
    queue<int> q;
    
    // Always start BFS from node 1
    q.push(1);
    vis[1] = 1;
    int count = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++; // Count visited nodes
        
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    // If we visited all N nodes, it is connected
    return count == n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mpp[a[i]]++;
    }

    // Optimization: If all elements are the same, it's a star graph (connected).
    if (mpp.size() == 1) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
        return;
    }

    // STRATEGY 1: Sort and Shift (Your original idea)
    sort(a.begin(), a.end());
    vector<int> candidate = a;
    
    // Perform Left Shift
    int first = candidate[0];
    for(int i=0; i<n-1; i++) candidate[i] = candidate[i+1];
    candidate[n-1] = first;

    if (isconnected(n, candidate)) {
        for (int i = 0; i < n; i++) cout << candidate[i] << " ";
        cout << "\n";
        return;
    }

    // STRATEGY 2: Random Shuffle fallback
    // If Sort+Shift failed (e.g. on input 1 1 2 2), try random shuffles.
    // 50 attempts is plenty and fits within time limits.
    int attempts = 50;
    while(attempts--) {
        random_shuffle(a.begin(), a.end());
        if(isconnected(n, a)) {
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int