#include <bits/stdc++.h>
using namespace std;
bool larger(const int& a, const int& b) {
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    vector<int> nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
    }
    sort(nums.begin(),nums.end(),larger);
        string re;
    for (const int& n : nums) {
        re += to_string(n);
    }
    cout<<re;


    return 0;
}