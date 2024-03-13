#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(int n,int c,vector<int> & dp){

    if(c==n){
        return 1;
    }
    if(dp[c]!=-1) return dp[c];
    ll cnt=0;
    for(int i=1;i<=6;i++){
        if(c+i<=n){
            cnt+=func(n,c+i,dp)%mod;
        }
        else break;
    }
    return dp[c]=cnt;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<int> dp(n + 1, -1);
        if(n > 0) {
            ll ways = func(n, 0,dp);
            cout << ways << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
