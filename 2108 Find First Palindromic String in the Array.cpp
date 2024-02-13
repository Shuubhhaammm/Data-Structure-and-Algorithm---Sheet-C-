class Solution {
public:
    bool check(string& str){
        int i=0; 
        int j=str.length()-1;

        while(i<=j){
            if(str[i]!=str[j]){
              return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string& str:words){
            if(check(str)) return str;
        }
        return "";
    }
};