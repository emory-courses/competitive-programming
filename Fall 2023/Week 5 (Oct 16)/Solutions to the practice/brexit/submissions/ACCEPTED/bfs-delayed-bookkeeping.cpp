#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using namespace std;

const int MIN_N = 2;
const int MAX_N = 200000; // 2 * 10^5
const int MIN_M = 1;
const int MAX_M = 300000; // 3 * 10^5

vector<int> neighbours[MAX_N];
int partnersLost[MAX_N];
bool processed[MAX_N];

int main() {
	int N, M, home, leave;
	cin >> N >> M >> home >> leave;
	assert(N >= MIN_N && N <= MAX_N);
	assert(M >= MIN_M && M <= MAX_M);
	assert(home >= 1 && home <= N);
	assert(leave >= 1 && leave <= N);
	home--; leave--;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		assert(A >= 1 && A <= N);
		assert(B >= 1 && B <= N);
		assert(A != B);
		A--; B--;
		neighbours[A].push_back(B);
		neighbours[B].push_back(A);
	}
	
	queue<int> q;
	q.push(leave);
	while (!q.empty() && !processed[home]) {
		int cur = q.front();
		q.pop();
		if (processed[cur]) continue; // process every vertex at most once
		processed[cur] = true;
		for (auto next : neighbours[cur]) {
			partnersLost[next]++;
			if (2 * partnersLost[next] >= (int) neighbours[next].size()) {
				
				// We should really only push if processed[next] is false.
				// 
				// However, we make sure at a later stage that every vertex
				// is processed at most once. Hence the queue will be slightly
				// larger than necessary, but apart from that the algorithm is
				// the same as the model solution.
				//
				// Amortised analysis shows that at most 2 * M elements are
				// pushed to the queue thoughout the execution of the entire
				// algorithm. Therefore this algorithm is still linear in
				// the input size, which is of course fast enough. :-)
				
				q.push(next);
			}
		}
	}
	
	cout << (processed[home] ? "leave" : "stay") << endl;
	
	return 0;
}
