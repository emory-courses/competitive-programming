/*
 * Slow solution for Brexit.
 *
 * To compile:
 *   g++ -std=c++11 -Wall -O2 joris_slowish.cc
 *
 * This program correctly uses a queue to visit each leaving country
 * exactly once. However the program does not keep track of the number
 * of trading partners of each country, instead it repeatedly counts
 * the number of parters.
 *
 * This program should probably be too slow.
 *
 * Time complexity O( nr_countries**2 )
 *   for suitably constructed worst-case input.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;


int main(void)
{
    // Read input.
    int k = -1, t = -1, x = -1, l = -1;
    scanf("%d %d %d %d", &k, &t, &x, &l);
    assert (k >= 2 && k <= 200000);
    assert (t >= 1 && t <= 300000);
    assert (x >= 1 && x <= k);
    assert (l >= 1 && l <= k);

    vector<vector<int>> trade(k+1);

    for (int i = 0; i < t; i++) {
        int a = -1, b = -1;
        scanf("%d %d", &a, &b);
        assert (a >= 1 && a < b && b <= k);
        trade[a].push_back(b);
        trade[b].push_back(a);
    }

    vector<bool> left(k+1);
    queue<int> q;

    // Remove country L.
    left[l] = true;
    q.push(l);

    // Process consequences.
    unsigned long nstep = 0;
    while (!left[x] && !q.empty()) {

        int a = q.front();
        q.pop();

        // Country P has left.
        // Figure out who else is leaving because of this.
        for (int b : trade[a]) {
            if (!left[b]) {
                unsigned int nfriend = 0;
                for (int c : trade[b]) {
                    nstep++;
                    if (!left[c]) {
                        nfriend++;
                    }
                }
                if (2 * nfriend <= trade[b].size()) {
                    left[b] = true;
                    q.push(b);
                }
            }
        }
    }

    // Write output.
    fputs(left[x] ? "leave\n" : "stay\n", stdout);
    fprintf(stderr, "nstep = %lu\n", nstep);

    return 0;
}

// end
