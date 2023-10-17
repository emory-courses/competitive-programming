// @EXPECTED_RESULTS@: WRONG-ANSWER,TIMELIMIT

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
bool removed[MAX_N];

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
	while (!q.empty() && !removed[home]) {
		int cur = q.front();
		q.pop();
		removed[cur] = true; // <-- bookkeeping done here
		for (auto next : neighbours[cur]) {
			partnersLost[next]++;
			if (2 * partnersLost[next] >= (int) neighbours[next].size() && !removed[next]) {
				q.push(next); // <-- should have been done here
			}
		}
	}
	
	cout << (removed[home] ? "leave" : "stay") << endl;
	
	return 0;
}
