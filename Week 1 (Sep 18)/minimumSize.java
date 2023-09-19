class Solution {
    public int minimumSize(int[] nums, int maxOperations) {

        int l = 1, r = (int)(1e9);
        while (l < r) {
            int m = (l+r)/2;
            if (canDo(nums,maxOperations,m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    public boolean canDo(int[] nums, int maxOp, int maxNum) {
        // check whether it is possible to have "maxNum" be the maximum balls in any certain bag
        long ct = 0;
        for (int i= 0; i < nums.length ;i++) {
            ct += (long)(nums[i])/maxNum;
            if (nums[i]%maxNum==0) ct--;
        }
        return ct<=maxOp;
    }
}