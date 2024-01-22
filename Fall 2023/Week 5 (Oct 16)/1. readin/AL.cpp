#include <iostream>
#include <tuple>
#include <vector>
#include <sstream>
using namespace std;

typedef pair<int, int> ii;  // Now 'ii' represents a pair of integers.
typedef vector<ii> vii;     // A vector of 'ii', which are pairs of integers.

int main(){
  int V;  // 'V' is now declared as an integer variable.
  scanf("%d", &V);

  vector<vii> AL(V, vii());  // 'AL' is a vector of vectors of integer pairs.

  for (int u = 0; u < V; ++u) {
    int total_neighbors; scanf("%d", &total_neighbors);
    while (total_neighbors--) {
      int v, w; scanf("%d %d", &v, &w); --v;  // The vertex index is 0-based.
      AL[u].emplace_back(v, w);  // Adding neighbors (with weights) to the adjacency list.
    }
  } 

  printf("Neighbors of vertex 0:\n");
  for (auto &[v, w] : AL[0])  // Using structured binding to access the pair of integers.
    printf("Edge 0-%d (weight = %d)\n", v, w);

  return 0;  // A non-void function should return a value.
}
