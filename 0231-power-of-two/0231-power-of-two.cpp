class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        double a= log10(n)/log10(2);
        if(ceil(a)==floor(a))
            return true;
        return false;
        
    }
};