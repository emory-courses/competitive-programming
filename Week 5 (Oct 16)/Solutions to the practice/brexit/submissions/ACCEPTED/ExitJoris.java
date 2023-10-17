/*
 * Solution to Brexit.
 *
 * Time complexity O( P ).
 */

import java.io.*;
import java.util.*;

public class ExitJoris
{

    public static void main(String[] args)
    {
        try {
            BufferedReader ir = new BufferedReader(
                                  new InputStreamReader(System.in));

            // Read input.
            String s = ir.readLine();
            String[] w = s.split(" ");
            assert(w.length == 4);
            int c = Integer.parseInt(w[0]);
            int p = Integer.parseInt(w[1]);
            int x = Integer.parseInt(w[2]);
            int l = Integer.parseInt(w[3]);
            assert (c >= 2 && c <= 200000);
            assert (p >= 1 && p <= 300000);
            assert (x >= 1 && x <= c);
            assert (l >= 1 && l <= c);

            ArrayList<ArrayList<Integer>> trade =
                new ArrayList<ArrayList<Integer>>(c+1);
            trade.add(null);
            for (int i = 1; i <= c; i++) {
                trade.add(new ArrayList<Integer>());
            }

            HashSet<Long> tradeset = new HashSet<Long>();

            for (int i = 0; i < p; i++) {
                s = ir.readLine();
                w = s.split(" ");
                assert (w.length == 2);
                int a = Integer.parseInt(w[0]);
                int b = Integer.parseInt(w[1]);
                assert (a >= 1);
                assert (b > a && b <= c);
                trade.get(a).add(b);
                trade.get(b).add(a);

                // Check that each pair occurs at most once.
                long h = (long)a * 1000000L + (long)b;
                assert (!tradeset.contains(h));
                tradeset.add(h);
            }

            // Check that each country has at least one trading partner.
            for (int i = 1; i <= c; i++) {
                assert (trade.get(i).size() > 0);
            }

            // Solve problem.
            boolean[] country_left = new boolean[c+1];
            int[] partners_left = new int[c+1];
            ArrayDeque<Integer> queue = new ArrayDeque<Integer>();

            country_left[l] = true;
            queue.add(l);

            while (!queue.isEmpty()) {
                int aa = queue.poll();
                for (int bb : trade.get(aa)) {
                    if (!country_left[bb]) {
                        partners_left[bb]++;
                        if (2 * partners_left[bb] >= trade.get(bb).size()) {
                            country_left[bb] = true;
                            queue.add(bb);
                        }
                    }
                }
            }

            // Write output.
            if (country_left[x]) {
                System.out.println("leave");
            } else {
                System.out.println("stay");
            }

        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

