class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        if(n%2==0) return 2==n;
        if(n%3==0) return 3==n;
        for(int i=5;i*i<n;i+=6){
            if(n%i==0 || n%(i+2)==0) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int prev=0;
        for(auto i:nums){
            int maxn=i-prev, maxPrime=0;
            for(int j=maxn-1;j>1;j--) {
                if(isPrime(j)){
                    maxPrime=j;
                    break;
                }
            }
            if(i-maxPrime<=prev) return false;
            prev=i-maxPrime;
        }
        return true;
    }
};
