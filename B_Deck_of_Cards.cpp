#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        string ans1(n, '+');
        int tp=0;
        int bt=n-1;
        string ans2(n, '+');
        int t2=0;
        int bt2=n-1;
        string ans3(n, '+');
        int t3=0;
        int bt3=n-1;
        string ans4(n, '+');
        int t4=0;
        int bt4=n-1;
        int rem1=0;
        int rem=0;
        int ind=0;
        while(ind<k){
            if (s[ind]=='0'){
                ans1[tp]='-';
                ans2[t2]='-';
                ans3[t3]='-';
                ans4[t4]='-';
                tp++;
                t2++;
                t3++;
                t4++;
            }
            else if (s[ind]=='1'){
                ans1[bt]='-';
                ans2[bt2]='-';
                ans3[bt3]='-';
                ans4[bt4]='-';
                bt--;
                bt2--;
                bt3--;
                bt4--;
            }
            else{
                ans1[tp]='-';
                ans2[bt2]='-';
                tp++;
                bt2--;
                if (rem%2==0){
                    ans3[t3]='-';
                    t3++;
                }
                else{
                    ans3[bt3]='-';
                    bt3--;
                }
                rem++;
                if (rem1%2==1){
                    ans4[t4]='-';
                    t4++;
                }
                else{
                    ans4[bt4]='-';
                    bt4--;
                }
                rem1++;
            }
            ind++;
        }
        string ans="";
        for (int i=0;i<n;i++){
            if (ans1[i]==ans2[i] && ans1[i]==ans3[i] && ans1[i]==ans4[i] && ans1[i]=='+'){
                ans+='+';
            }
            else if (ans1[i]==ans2[i] && ans1[i]==ans3[i] && ans1[i]==ans4[i] && ans1[i]=='-'){
                ans+='-';
            }
            else{
                ans+='?';
            }
        }
        cout<<ans<<"\n";
    }
}