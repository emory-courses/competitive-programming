#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

const int MIN_C = 2;
const int MAX_C = 200000; // 2 * 10^5
const int MIN_P = 1;
const int MAX_P = 300000; // 3 * 10^5

int C, P, X, L;

vector<int> neighbours[MAX_C];
int degree[MAX_C];

int main() {
	cin >> C >> P >> X >> L;
	assert(C >= MIN_C && C <= MAX_C);
	assert(P >= MIN_P && P <= MAX_P);
	assert(X >= 1 && X <= C);
	assert(L >= 1 && L <= C);
	X--; L--;
	for (int i = 0; i < P; i++) {
		long long A, B;
		cin >> A >> B;
		assert(A >= 1 && A <= C);
		assert(B >= 1 && B <= C);
		assert(A < B);
		A--; B--;
		neighbours[A].push_back(B);
		neighbours[B].push_back(A);
	}
	for (int i = 0; i < C; i++) {
		degree[i] = neighbours[i].size();
	}
	queue<int> leave;
	leave.push(L);
	int numLeave = 0;
	while (!leave.empty()) {
		int cur = leave.front();
		leave.pop();
		degree[cur] = 0;
		numLeave++;
		//cerr << "  country " << cur + 1 << " is leaving the union..." << endl;
		for (vector<int>::iterator it = neighbours[cur].begin(); it != neighbours[cur].end(); it++) {
			if (degree[*it]) {
				degree[*it]--;
				if (degree[*it] == (int) neighbours[*it].size() / 2) {
					leave.push(*it);
				}
			}
		}
	}
	#ifndef ONLINE_JUDGE
		cerr << "  " << numLeave << " countr" << (numLeave == 1 ? "y" : "ies") << " left the union, " << C - numLeave << " stayed." << endl;
	#endif
	cout << (degree[X] <= (int) neighbours[X].size() / 2 ? "leave" : "stay") << endl;
	return 0;
}
