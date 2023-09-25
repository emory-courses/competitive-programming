#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

struct myComp{
	bool operator () (const pair<string, int>& a, const pair<string, int>& b) const {
		if( a.second > b.second ) return true;
		if( b.second > a.second ) return false;
		return a.first < b.first;
	}
};

int main(void) {
	map<string,string> M;	
	
	int N;
	cin >> N;
	while(N--) {
		string user;
		cin >> user;
		string message;
		getline(cin, message);
		if( M.find(user) == M.end() ) {
			M[user] = message;
		}
		else {
			M.find(user)->second = M.find(user)->second + " " + message;
		}
	}
	map<string,int> S;
	unordered_set<string> used;
	for( map<string,string>::iterator iter = M.begin(); iter != M.end(); iter++ ) {
		stringstream s(iter->second);
		string word;
		unordered_set<string> incurmsg;
		while( s >> word ) {
			if( iter == M.begin() ) {
				used.insert(word);
			}
			incurmsg.insert(word);
			if( S.find(word) == S.end() ) {
				S[word] = 1;
			}
			else {
				S[word] = S[word] + 1; 
			}
		}
		vector<string> toremove;
		for( unordered_set<string>::iterator iter2 =  used.begin(); iter2 != used.end(); iter2++ ) {
			if( incurmsg.find(*iter2) == incurmsg.end() ) {
				toremove.push_back( *iter2 );
			}
		}
		for( int i = 0; i < toremove.size(); ++i ) {
			used.erase(toremove[i]);
		}
	}
	vector< pair<string,int> > res;
	for( unordered_set<string>::iterator iter2 = used.begin(); iter2 != used.end(); iter2++ ) {
		res.push_back( make_pair( *iter2, S[*iter2] ) );
	}

	sort(res.begin(), res.end(), myComp());
	for( int i = 0; i < res.size(); ++i ) {
		cout << res[i].first << endl;
	}
	if( ! res.size() ) cout << "ALL CLEAR" << endl;
	return 0;
}
