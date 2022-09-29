#include <bits/stdc++.h> // Include every library
using namespace std;

// Declared globally, thus initialized to 0 automatically
// We set the length of a as the largest possible value of n,
// plus 5 just in case (personal preference)
int n;
long long a[100005];

int main(){
    // This makes cin/cout as fast as prinf/scanf
    // If you include this line, NEVER use printf/scanf as they break functionality
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n; // Read n
    // Alternatively scanf("%d", &n);
    for(int i = 0; i < n; i++){
    	cin >> a[i]; // Read the array
    	// Alternatively scanf("%lld", &a[i]);
    }
    sort(a, a + n); // C++ STL sort function, uses quicksort/mergesort to sort in O(nlogn)
    for(int i = 0; i < n; i++){
    	cout << a[i] << ' '; // Print the array with spaces
    	// Alternatively printf("%lld ", a[i]);
    }
    cout << '\n'; // Never use cout << endl, it is much slower since it flushes the output
    // Alternatively printf("\n");   
}
