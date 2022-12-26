class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = nums[0] ;
        for (int i = 0 ; i < nums.size()-1 ; i++){
            
            if (ans == 0 ){
                return 0 ;
            }
            ans = max(ans-1 , nums[i+1]);
        }
    return 1 ;
    }
};