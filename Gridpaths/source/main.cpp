#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll countPaths(int row, int col, vector<vector<char>>& matrix, int size, vector<vector<int>>& memo) {
    if (row < 0 || col < 0 || row >= size || col >= size) {
        return 0;
    }
    if (matrix[row][col] == '*') {
        return 0;
    }
    if (row == size - 1 && col == size - 1) {
        return 1;
    }
    if (memo[row][col] != -1) {
        return memo[row][col];
    }
    ll downPaths = countPaths(row + 1, col, matrix, size, memo) % mod;
    ll rightPaths = countPaths(row, col + 1, matrix, size, memo) % mod;
    return memo[row][col] = (downPaths + rightPaths) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    ll testCases;
    cin >> testCases;
    while(testCases--) {
        ll size;
        cin >> size;
        vector<vector<char>> matrix(size, vector<char>(size, '0'));
        vector<vector<int>> memo(size + 1, vector<int>(size + 1, -1));
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                char cell;
                cin >> cell;
                matrix[i][j] = cell;
            }
        }
        ll paths = countPaths(0, 0, matrix, size, memo);
        cout << paths << endl;
    }
    return 0;
}
