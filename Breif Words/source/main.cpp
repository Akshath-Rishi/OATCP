#include <bits/stdc++.h>
using namespace std;

void generateSubsequences(const string& word, int maxLength, unordered_set<string>& subsequences) {
    int n = word.length();
    for (int len = 1; len <= maxLength; ++len) {
        for (int start = 0; start <= n - len; ++start) {
            string subsequence;
            int count = 0;
            for (int i = start; i < n && count < len; ++i) {
                subsequence.push_back(word[i]);
                count++;
            }
            subsequences.insert(subsequence);
        }
    }
}

unordered_map<string, string> assign(const vector<string>& words) {
    unordered_map<string, string> wtsf; 
    unordered_set<string> usf;
    
    for (const auto& word : words) {
        if (word.length() <= 4) { 
            wtsf[word] = word;
            usf.insert(word);
            continue;
        }
    
        unordered_set<string> subsequences;
        generateSubsequences(word, 4, subsequences);

        for (const auto& subseq : subsequences) {
            if (usf.find(subseq) == usf.end()) {
                wtsf[word] = subseq;
                usf.insert(subseq);
                break;
            }
        }
        if (wtsf.find(word) == wtsf.end()) {
            cout << "No unique short form found for word: " << word << endl;
        }
    }

    return wtsf; 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    
    auto shortForms = assign(words);
    for (const auto& pair : shortForms) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;  
}