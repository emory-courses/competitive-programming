#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto& x : c) cin >> x;

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n && cnt < i; ++j)
            if (c[j] >= i) ++cnt;
        if (cnt < i) {
            cout << i-1 << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}
