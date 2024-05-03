#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt"); 

    vector<int> nums;
    int x;
     while (cin >> x) {
        nums.push_back(x);
        if (cin.get() == '\n') 
            break;
    }
    int n;
    cin >> n;
    x=0;
    x++;
    int toa = 1, re = 0, i = 0;
    while (toa <= n) {
        if (i < nums.size() && nums[i] <= toa) {
            toa += nums[i++];
        } else {
            toa += toa;
            re++;
        }
    }
    cout << re ;
    return 0;
}