class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length-1;
        // l is left pointer, answer must be to the right
        //r is right pointer, answer must be to the left
        while (l < r) {
            int m = (l+r)/2;
            if (nums[m]==target) {
                return m;
            }
            if (nums[m]<target) {
                l = m + 1;
            }
            if (nums[m]>target) {
                r = m - 1;
            }
            // [1, 3, 5, 6, 7, 8, 9, 10, 12, 15, 17]
        }
        if (nums[l]==target) return l;
        return -1;
    }
}