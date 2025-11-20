//lc 2523
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<=right+1;i++){
            if(isPrime[i]){
                for(int j=i*i;j<right+1;j+=i) isPrime[j]=false;
            }
        }
        vector<int>primes,ans={-1,-1};
        int mini=INT_MAX;
        for(int i=left;i<=right;i++){
            if(isPrime[i]) {
                if(primes.size()>=1 && i-primes.back()<mini) {
                    mini=i-primes.back();
                    ans={primes.back(),i};
                }
                primes.push_back(i);
            }
        }

        return ans;
    }
};
