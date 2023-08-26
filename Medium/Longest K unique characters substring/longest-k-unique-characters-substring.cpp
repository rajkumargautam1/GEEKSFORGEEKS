//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int n = s.length();
    
    // Initialize variables to track the unique characters and their counts.
    unordered_map<char, int> charCount;
    int maxLength = -1;
    
    int left = 0; // Start of the current substring.
    
    for (int right = 0; right < n; right++) {
        char currentChar = s[right];
        charCount[currentChar]++;
        
        // Shrink the window from the left side if there are more than K unique characters.
        while (charCount.size() > k) {
            char leftChar = s[left];
            charCount[leftChar]--;
            if (charCount[leftChar] == 0) {
                charCount.erase(leftChar);
            }
            left++; // Move the left pointer to the right.
        }
        
        // Update the maximum length if a valid substring is found.
        if (charCount.size() == k) {
            maxLength = max(maxLength, right - left + 1);
        }
    }
    
    return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends