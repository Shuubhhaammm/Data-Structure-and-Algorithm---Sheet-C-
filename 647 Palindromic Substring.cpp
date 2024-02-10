#include<string> 
using namespace std;

class Solution {
public:
    bool isPalindrom(string &s, int i, int j){
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    int countSubstrings(string s) {
        int i=0, j=0;
        int n=s.length();
        int count=0;
        for(i=0; i<n; i++)
        {
            for(j=i; j<n; j++)
            {
                if(isPalindrom(s, i, j)){
                    count++;
                }
            }

        }
        return count;
    }
};