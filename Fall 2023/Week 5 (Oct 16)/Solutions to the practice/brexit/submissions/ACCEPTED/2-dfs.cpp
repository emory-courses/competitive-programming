// This solution uses DFS instead of BFS. It will be fine on DOMjudge, but it
// is likely to crash on your home computer (due to stack overflow).

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int MIN_C = 2;
const int MAX_C = 200000; // 2 * 10^5
const int MIN_P = 1;
const int MAX_P = 300000; // 3 * 10^5

vector<int> neighbours[MAX_C];
int degree[MAX_C];
int visited[MAX_C];

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	for (auto y : neighbours[x]) {
		if (degree[y] == 0) continue;
		degree[y]--;
		if (degree[y] == ((int) neighbours[y].size() / 2)) {
			dfs(y);
		}
	}
}

int main() {
	int C, P, X, L;
	cin >> C >> P >> X >> L;
	assert(C >= MIN_C && C <= MAX_C);
	assert(P >= MIN_P && P <= MAX_P);
	assert(X >= 1 && X <= C);
	assert(L >= 1 && L <= C);
	X--; L--;
	for (int i = 0; i < P; i++) {
		int A, B;
		cin >> A >> B;
		assert(A >= 1 && A <= C);
		assert(B >= 1 && B <= C);
		A--; B--;
		neighbours[A].push_back(B);
		neighbours[B].push_back(A);
		degree[A]++;
		degree[B]++;
	}
	dfs(L);
	cout << (visited[X] ? "leave" : "stay") << endl;
	return 0;
}
