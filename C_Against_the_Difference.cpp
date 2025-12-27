#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        map<int,int>mpp;
        for (int i=0;i<n;i++){
            mpp[a[i]]++;
        }
        int cnt=0;
        for (auto it:mpp){
            cnt+=(it.second/it.first);
        }
        cout<<cnt<<endl;
    }
}

    long long maxProduct(vector<int>& nums) {
        unordered_map<int,int> best;
        for (int num : nums) {
            best[num] = max(best[num], num); 
        }
        vector<int> m;
        for (auto &p : best){
            m.push_back(p.first);
        }
        long long ans = 0;
        int n = m.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if ((m[i] & m[j]) == 0) {
                    ans = max(ans, 1LL * best[m[i]] * best[m[j]]);
                }
            }
        }
        return ans;
    }