class Solution {
public:
    
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        stack<int> pos;
        stack<int> neg;

        for(int i=0; i<n; i++){
            if(nums[i]>0) pos.push(nums[i]);
            else if(nums[i]<0) neg.push(nums[i]);
        }

        for(int i=n-1; i>=0; i--){
            if(i%2 != 0){
                nums[i] = neg.top();
                neg.pop();
            }
            else{
                nums[i] = pos.top();
                pos.pop();
            }
        }
        return nums;
    }
};