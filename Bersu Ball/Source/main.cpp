#include <bits/stdc++.h>
using namespace std;

int bersuball(int p1,int p2,vector<int> &boys,vector<int> &girls,int n,int m,vector<vector<int>>&dp){
    if(p1>=n || p2>=m){
        return 0;
    }
    if(dp[p1][p2]!=-1) return dp[p1][p2];
    int tk=INT_MIN,nt;
    if(boys[p1]==girls[p2]|| abs(boys[p1]-girls[p2])==1){
        tk=1+bersuball(p1+1,p2+1,boys,girls,n,m,dp);
    }
    int mb=bersuball(p1+1,p2,boys,girls,n,m,dp);
    int mg=bersuball(p1,p2+1,boys,girls,n,m,dp);
    nt=max(mb,mg);
    return dp[p1][p2]=max(tk,nt); 
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    int n;
    cin>>n;
    vector<int>b,g;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;b.push_back(x);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;g.push_back(x);
    }
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=bersuball(0,0,b,g,n,m,dp);
    cout<<ans;


    return 0;
}