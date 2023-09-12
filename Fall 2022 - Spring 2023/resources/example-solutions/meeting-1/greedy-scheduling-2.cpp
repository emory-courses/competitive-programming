#include <bits/stdc++.h>
using namespace std;
/*
O(nlogn) greedy solution to scheduling problem 2
*/

int n;
pair<int,int> events[100005]; // first is duration, second is deadline

bool comp(pair<int,int> a, pair<int,int> b){
	return (a.first < b.first); // sort increasing by duration
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> events[i].first >> events[i].second;
    }
    sort(events, events + n, comp);
    int answer = 0, current_ending_time = 0;
    for(int i = 0; i < n; i++){
    	current_ending_time += events[i].first;
    	answer += events[i].second - current_ending_time;
    }
    cout << answer << '\n';

}
