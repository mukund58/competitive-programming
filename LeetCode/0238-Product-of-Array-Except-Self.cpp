// o(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
            vector<int> suff(n);
            vector<int> pre(n);
                    suff[n - 1] = 1;
                    pre[0] = 1;
            for(int i =1; i <n ;i++){
                pre[i] = (nums[i-1] * pre[i-1]);
            }

            for(int i =n-2; i >=0 ;i--){
                suff[i] = (nums[i+1] * suff[i+1]);
            }

            for(int i =0; i <n ;i++){
                output[i] = (pre[i] * suff[i]);
            }
        return output;
    }
};


