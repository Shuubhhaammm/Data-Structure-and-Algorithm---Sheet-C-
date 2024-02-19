class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;

        while(n%2==0) n/=2;
        return n==1;
    }
};

// Keep dividing the number by two, i.e, do n = n/2 iteratively.
// In any iteration, if n%2 becomes non-zero and n is not 1 then n is not a power of 2.
// If n becomes 1 then it is a power of 2

// 2^0= 1
// 2^1= 2  => 2%2=0 
// 2^2= 4  => 4%2=0
// 2^3= 8  => 8%2=0
// 2^4= 16 => 16%2=0
// 2^5= 32 => 32%2=0