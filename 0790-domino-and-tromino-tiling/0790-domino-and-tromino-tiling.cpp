class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        vector<int>second(2,0);
        vector<int>first(2,0);
        vector<int>curr(2,0);
        first[0] = 1;
        for(int i = n - 1;i >= 0;i--) {
            for(int j = 1;j >= 0;j--) {
                if(j) {
                    long gapchoice1 = first[1];
                    long gapchoice2 = first[0];
                    curr[j] = (gapchoice1 + gapchoice2) % mod;
                }
                else {
                    long normalchoice1 = first[0];
                    long normalchoice2 = second[0];
                    long normalchoice3 = second[1];
                    curr[j] = (normalchoice1 + normalchoice2 + 2*normalchoice3) % mod;
                }
            }
            second = first;
            first = curr;
        }
        return first[0];
    }
};