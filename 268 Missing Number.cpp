class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i==nums[i]) continue;

            return i;
        }
        return n;
    }
};

//                  nums[]= {3,0,1}
//  after sorting:- nums[]= {0,1,3}
//                           ^ ^ ^ 
//                           | | |
//                           0 1 2 