class Solution {
    public int mySqrt(int xx) {
        long x = (long)xx;
        long left = 0, right = x;
        while (left < right) {
            long middle = (right+left+1)/2;

            long square = middle * middle;
            long square2 = (middle+1)*(middle+1);

            if (square == x) {
                return (int)middle;
            }

            if (square < x) {
                left = middle;
                //if (square2 > x) return middle;
            }
            if (square > x) {
                right = middle - 1;
            }
        }
        return (int)left;
    }
}