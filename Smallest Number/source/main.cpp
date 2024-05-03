#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007  // Constants and macros
#define LL long long  // Macro for long long type

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream input("input.txt");
    ofstream output("../output/output.txt");
    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening file(s)" << endl;
        return 1;
    }

    string num;  
    LL k;  
    input >> num;
    input >> k;

    string ans = ""; 
    for (char &c : num) {
        while (!ans.empty() && ans.back() > c && k > 0) {
            ans.pop_back();
            k--; 
        }
        if (!ans.empty() || c != '0') {
            ans.push_back(c);
        }
    }
    while (!ans.empty() && k-- > 0) {
        ans.pop_back();
    }
    if (ans.empty()) {
        ans = "0";
    }
    LL re = stoll(ans);  
    output << re << endl;

    return 0;  
}