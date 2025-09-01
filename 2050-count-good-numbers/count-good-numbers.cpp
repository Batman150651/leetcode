class Solution {
public:
    long long power(long long base, long long exp, long long mod){
        if(exp==0) return 1;
        base%=mod;
        if(exp%2==0){
            return power((base*base)%mod,exp/2,mod);
        }
        else{
            return (base*power(base,exp-1,mod))%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long mod = 1e9+7;
        return (power(5,even,mod)*power(4,odd,mod))%mod;
    }
};