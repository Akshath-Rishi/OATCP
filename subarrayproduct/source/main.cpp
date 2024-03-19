#include <bits/stdc++.h>
using namespace std;
int funct(vector<int> &a,int n){
    int p1=a[0],p2=a[0],maxi=a[0];
    for(int i=1;i<n;i++){
        int temp=max({a[i],p1*a[i],p2*a[i]});
        p2=min({a[i],p1*a[i],p2*a[i]});
        p1=temp;
        maxi=max(maxi,p1);
    }
    return maxi;
}
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int ans=funct(a,n);
        cout<<ans;

    return 0;
}