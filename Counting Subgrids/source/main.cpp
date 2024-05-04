#include <bits/stdc++.h>
using namespace std;
int csub(int n,vector<vector<int>>& matrix) {
    
    vector<int> row(n); 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            row[i] |= matrix[i][j] << (n - j);         }
    }

    int ans = 0; 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int bits = __builtin_popcount(row[i] & row[j]);
            int count = bits * (bits - 1) / 2;
            ans += count;
        }
    }

    return ans; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    int n;
    cin>>n;
     vector<vector<int>> nums(n,vector<int>(n));
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>nums[i][j];
    }
   }
    int re=csub(n,nums);
    cout << re << endl;

    return 0;  
}