import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Scanner;
import java.io.PrintStream;
 

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Solution solver = new Solution();
        solver.solve(in, System.out);
    }

    static class Solution {
        int n;
        long[] a;
 
        public void solve(Scanner in, PrintStream out) {
            n = in.nextInt();
            a = new long[n];
            for (int i = 1; i < n; i++) a[i] = in.nextLong();
            Arrays.sort(a);
            for (int i = 0; i < n; i++) out.print(a[i] + " ");
            out.println();
        }
 
    }
}
 
