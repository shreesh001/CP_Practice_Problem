#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Ordered set supporting order statistics (order_of_key, find_by_order)
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int32_t main() {
		ios::sync_with_stdio(false); // speed up I/O
		cin.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				int n;
				cin >> n;
				vector<pair<int, int>> vec(n); // vec[i] = {a_i, b_i}
				for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;

				// Sort by starting position a_i. After this, a_i are increasing.
				sort(vec.begin(), vec.end());

				Oset st;          // stores b's of processed people (ordered)
				long long ans = 0; // total number of greetings

				for (int i = 0; i < n; i++) {
						// Among previously seen intervals (i of them), count how many have b > current b.
						// This equals i - (# of previous b's < current b).
						// Each such inversion (a_j < a_i but b_j > b_i) corresponds to exactly one greeting.
						ans += i - st.order_of_key(vec[i].second);
						st.insert(vec[i].second); // add current b for future comparisons
				}

				cout << ans << '\n';
		}

		return 0;
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(n)
*/
