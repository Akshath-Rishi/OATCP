#include <bits/stdc++.h>
using namespace std;
int totalHammingDistance(const std::vector<int>& nums) {
    int n = nums.size();
    int totalDistance = 0;
    int numBits = 32; 
    for (int i = 0; i < numBits; ++i) {
        int countOnes = 0; 
        for (int num : nums) {
            if (num & (1 << i)) { 
                countOnes++;
            }
        }
        int countZeros = n - countOnes; 
        totalDistance += countOnes * countZeros;
    }

    return totalDistance;
}

int main() {
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
    int re=totalHammingDistance(nums);
    cout << re << endl;

    return 0;  
}