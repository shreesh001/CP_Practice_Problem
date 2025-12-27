#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> arr(2*n+1,0);
        int num=n;
        int i=1;
        while(num>n/2){
            arr[i]=num;
            arr[i+num]=num;
            num--;
            i+=2;
        }
        i=2;
        while(num>1){
            arr[i]=num;
            int j=i;
            while (j <= 2*n && arr[j] != 0) j += num;
            arr[j]=num;
            num--;
            i+=2;
        }
        for (int i=1;i<=2*n;i++){
            if (arr[i]==0) arr[i]=1;
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}