#include <bits/stdc++.h>
using namespace std;
/*
O(nlogn) greedy solution to scheduling problem 1
*/

int n;
pair<int,int> events[100005]; // first is starting time, second is ending time

bool comp(pair<int,int> a, pair<int,int> b){
	return (a.second < b.second); // sort increasing by ending time
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> events[i].first >> events[i].second;
    }
    sort(events, events + n, comp);
    int answer = 0, last_ending_time = 0;
    for(int i = 0; i < n; i++){
    	if(events[i].first >= last_ending_time){
    		answer++;
    		last_ending_time = events[i].second;
    	}
    }
    cout << answer << '\n';

}