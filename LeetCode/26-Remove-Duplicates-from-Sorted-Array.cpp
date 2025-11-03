class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        int res = 1;

        while(j<n){

            // if(n == 1) return res;
            if(nums[j] == nums[j-1]){
                j++;
                continue;
            }
            // uniqe element
            nums[i+1] = nums[j];
            j++;
            i++;
            res++;
        }
        return res;
    }
};
