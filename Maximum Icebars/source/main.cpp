#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    int n;
    cin>>n;
    vector<int>cost;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;cost.push_back(x);
    }
    int amt,j=0,re=0;
    cin>>amt;
    sort(cost.begin(),cost.end());
    while(amt>0 && j<n ){
        if(cost[j]<=amt){
            amt-=cost[j];
            j++;
            re++;
        }
    }   
    cout<<j;


    return 0;
}