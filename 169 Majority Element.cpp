class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size()/2;

        for(auto i : nums){
            mp[i]++;
        }
        int ans=0;
        for(auto m:mp){
            if(m.second > n){
                ans=m.first;
            }
        }
        
        return ans;
    }
};