#include <iostream>
#include <tuple>
#include <vector>
#include <sstream>
using namespace std;

const int MAX_V = 1010;


int AM[MAX_V][MAX_V];

int main(){
	int V; scanf("%d", &V);  
	for (int u = 0; u < V; ++u)                    // if V is > 2000,
    		for (int v = 0; v < V; ++v)                  // try NOT to use AM
      			scanf("%d", &AM[u][v]);
	
	printf("Neighbors of vertex 0:\n");
	for (int v = 0; v < V; ++v)                    // O(V)
    		if (AM[0][v])
      		printf("Edge 0-%d (weight = %d)\n", v, AM[0][v]);

}
