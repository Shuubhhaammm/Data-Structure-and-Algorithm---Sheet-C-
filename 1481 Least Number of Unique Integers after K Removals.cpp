class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto i: arr){
            mp[i]++;
        }
        vector<int> freq;
        for(auto i: mp){
            freq.push_back(i.second);
        }

        sort(freq.begin(), freq.end());
        int ans=0;
        int n=freq.size();
        for(int i=0; i<freq.size(); i++){
            if(k < freq[i]){
               ans = n-i;
               break;
            } 
            k=k-freq[i];
        }

        return ans;
    }
};