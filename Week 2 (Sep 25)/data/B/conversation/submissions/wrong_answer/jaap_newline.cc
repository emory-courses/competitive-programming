#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int cmp(pair<string,int> a, pair<string,int> b)
{
	if ( a.second!=b.second ) return a.second>b.second;
	return a.first<b.first;
}

int main()
{
	int n;
	char c;
	cin >> n >> c; // consume newline for later line based input

	map<string,map<string,int> > userfreq;

	for(int i=0; i<n; i++) {
		string name, msg, word;
		cin >> name;
		getline(cin,msg);
		istringstream ss(msg);
		while ( ss>>word ) userfreq[name][word]++;
	}

	map<string,int> freq = userfreq.begin()->second;
	for(auto i=++userfreq.begin(); i!=userfreq.end(); ++i) {
		map<string,int> &curr = i->second;
		map<string,int> newfreq;
		for(auto j=freq.begin(); j!=freq.end(); ++j) {
			string word = j->first;
			if ( i->second.count(word) ) newfreq[word] = freq[word] + curr[word];
		}
		freq = newfreq;
	}

	vector<pair<string,int> > words(freq.begin(),freq.end());

	sort(words.begin(),words.end(),cmp);
	if ( words.size()==0 ) cout << "ALL CLEAR" << endl;
	for(size_t i=0; i<words.size(); i++) cout << words[i].first << endl;

	return 0;
}
