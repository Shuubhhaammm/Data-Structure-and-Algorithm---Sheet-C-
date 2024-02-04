#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        int n= s.length();
        int countRequired = t.size();
        unordered_map<char, int> mp;

        for(char &ch : t)
        {
            mp[ch]++;
        }
        
        int i=0, j=0;
        int winSize = INT_MAX;
        int startIdx =0;  

        while(j<n){
            char ch = s[j];

            if(mp[ch]>0)
               countRequired--;
            
            mp[ch]--;
            
            //shrinking the size by increasing i-index
            while(countRequired ==0){
                int currWindowSize = j-i+1;
                if(winSize > currWindowSize){
                    winSize = currWindowSize;
                    startIdx =i;
                }  
                mp[s[i]]++;
                if(mp[s[i]]>0)
                {
                    countRequired++;
                }
                i++; 
            }
            j++;
        } 
        return winSize == INT_MAX ? "" : s.substr(startIdx, winSize);
    }
};

/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/