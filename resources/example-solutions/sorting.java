import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Scanner;
 

public class Main {
    
    public static void main(String[] args) {
        Solution solver = new Solution();
        solver.solve();
    }

    static class Solution {
        int n;
        long[] a;
 
        public void solve() {
            Scanner in = new Scanner(System.in);
            n = in.nextInt();
            a = new long[n];
            for (int i = 1; i < n; i++) a[i] = in.nextLong();
            Arrays.sort(a);
            for (int i = 0; i < n; i++) System.out.print(a[i] + " ");
            System.out.println();
        }
 
    }
}
 
