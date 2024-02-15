class Solution {
public:

    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
         int n=nums.size();
         long long sum=0;
         long long ans=0;
        for(int i=0; i<n; i++){
           if(nums[i]<sum){
               ans = sum + nums[i];
           }
           sum = sum + nums[i];
        }
        return ans==0 ? -1 : ans;
    }
};

///nums[]=  {1, 3, 4, 5}   sum=0, ans=0; 
// a. nums =1 | 1<0=F | sum = sum + 1 = 2      | ans=0
// b. nums =3 | 3<2=F | sum = 2+3=5            | ans=0
// c. nums =4 | 4<5=F | sum = 5+4=9            | ans=0
// d. nums =5 | 5<9=T | Enter into codintion   | ans=sum+5=9+5=14  
/// out from loop | check if ans == 0 | if yes, return -1 | if no, return ans