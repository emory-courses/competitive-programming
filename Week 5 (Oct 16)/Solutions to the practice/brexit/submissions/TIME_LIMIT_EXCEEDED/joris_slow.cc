/*
 * Slow solution for Brexit.
 *
 * To compile:
 *   g++ -std=c++11 -Wall -O2 joris_slowish.cc
 *
 * This program repeatedly scans the list of countries to determine
 * who has left, but tries to be very quick about it.
 *
 * This program should be too slow.
 *
 * Time complexity O( nr_countries**2 ).
 */

#include <stdio.h>
#include <assert.h>
#include <vector>

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
    vector<unsigned int> friends(k+1);

    for (int i = 0; i < t; i++) {
        int a = -1, b = -1;
        scanf("%d %d", &a, &b);
        assert (a >= 1 && a < b && b <= k);
        trade[a].push_back(b);
        trade[b].push_back(a);
        friends[a]++;
        friends[b]++;
    }

    vector<bool> left(k+1);

    // Remove country L.
    left[l] = true;
    for (int p : trade[l]) {
        friends[p]--;
        if (!left[p] && 2 * friends[p] <= trade[p].size()) {
            // Also remove country P.
            left[p] = true;
            for (int q : trade[p]) {
                friends[q]--;
            }
        }
    }

    // Process consequences.
    bool changed = true;
    while (changed && !left[x]) {
        changed = false;
        for (int i = 1; i <= k; i++) {
            if (!left[i] && 2 * friends[i] <= trade[i].size()) {
                changed = true;
                left[i] = true;
                for (int p : trade[i]) {
                    friends[p]--;
                    if (!left[p] && 2 * friends[p] < trade[p].size()) {
                        left[p] = true;
                        for (int q : trade[p]) {
                            friends[q]--;
                        }
                    }
                }
            }
        }
    }

    // Write output.
    fputs(left[x] ? "leave\n" : "stay\n", stdout);

    return 0;
}

// end
