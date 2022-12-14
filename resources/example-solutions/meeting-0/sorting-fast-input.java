import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
 

public class Main {

    // Template for main function
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solution solver = new Solution();
        solver.solve(in, out);
        out.close();
    }
 
    static class Solution {
        int n;
        long[] a;
 
        public void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            a = new long[n];
            for (int i = 1; i < n; i++) a[i] = in.nextLong();
            Arrays.sort(a);
            for (int i = 0; i < n; i++) out.print(a[i] + " ");
            out.println();
        }
 
    }

    // Class for fast input, System.in is too slow
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int nextLong() {
            return Long.parseLong(next());
        }
 
    }
}
 
