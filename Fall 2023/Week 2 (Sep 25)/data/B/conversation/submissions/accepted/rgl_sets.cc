#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
  int lines; cin>>lines;
  map<string,int> users;
  map<string,pair<int,set<int>>> used;
  for (string s; getline(cin,s);) if (s.length()){
    stringstream sst(s);
    string user,word; sst>>user; assert(user.length()<=20);
    int uid=(users[user]?users[user]:users[user]=users.size());
    while (sst>>word){
      used[word].second.insert(uid);
      used[word].first--;
    }
  }
  vector<pair<int,string>> res;
  for (auto i: used)
    if (i.second.second.size()==users.size())
      res.emplace_back(i.second.first,i.first);
  sort(res.begin(),res.end());
  for (auto const &i: res) cout<<i.second<<endl;
  if (res.empty()) cout<<"ALL CLEAR\n";
}
