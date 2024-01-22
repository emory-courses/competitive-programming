import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class hindex_da {
    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        sc.close();
        Arrays.sort(a);

        int best = 0;
        int total = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= ++total && total > best) best = total;
        }

        System.out.println(best);
    }

    public static void main(String[] args) {
        new hindex_da().work();
    }
}
