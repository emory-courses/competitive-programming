#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>  // for sort()
using namespace std;

typedef tuple<int, int, int> iii;  // 'iii' represents a triplet of integers.

int main(){
  int E;  // 'E' represents the number of edges.
  scanf("%d", &E);

  vector<iii> EL(E);  // 'EL' is a vector of 'iii', which are triplets of integers.

  // Reading the edges and storing them in 'EL'.
  for (int i = 0; i < E; ++i) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    EL[i] = make_tuple(w, u, v);  // Storing the weight first makes sorting by weight straightforward.
  }

  // Sorting 'EL' by the weights of the edges (the first element of the tuples).
  sort(EL.begin(), EL.end());

  // Printing the edges, now sorted by weight.
  printf("Edges sorted by weight (smallest to largest):\n");
  for (auto &[w, u, v] : EL)  // Using structured binding to access the elements of the tuples.
    printf("weight: %d (%d-%d)\n", w, u, v);

  return 0;  // A non-void function should return a value.
}

