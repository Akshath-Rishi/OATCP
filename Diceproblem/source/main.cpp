#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll calculateWays(ll targetSum, ll currentSum, vector<int> &memo) {
    if(targetSum == currentSum) {
        return 1;
    }
    if(memo[currentSum] != -1) {
        return memo[currentSum];
    }
    ll totalWays = 0;
    for(int diceValue = 1; diceValue <= 6; diceValue++) {
        if((currentSum + diceValue) <= targetSum) {
            totalWays += calculateWays(targetSum, currentSum + diceValue, memo) % MOD;
        } else {
            break;
        }
    }
    return memo[currentSum] = totalWays % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt"); 
    ll testCases;
    cin >> testCases;
    while(testCases--) {
        ll target;
        cin >> target;
        vector<int> memo(target + 1, -1);
        if(target > 0) {
            ll ways = calculateWays(target, 0, memo);
            cout << ways << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
