#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto& x : c) cin >> x;

    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    int mx = 0;
    for (int i = 0; i < n; ++i)
        if (c[i] >= i+1)
            mx = i+1;
    cout << mx << endl;

    return 0;
}
