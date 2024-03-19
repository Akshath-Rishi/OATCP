#include <bits/stdc++.h>
using namespace std;

int maxrotatek(vector<int> &arr,int n){
    int sum=0,f=0;
     for (int i = 0; i < n; ++i) {
        sum += arr[i];
        f += i * arr[i];
    }
    
    int maxRotate = f;

    for (int i = 1; i < n; ++i) {
        f = f + sum - n * arr[n - i];
        maxRotate = max(maxRotate, f);
        
    }

    return maxRotate;

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
        int ans=maxrotatek(a,n);
        cout<<ans; 

    return 0;
}