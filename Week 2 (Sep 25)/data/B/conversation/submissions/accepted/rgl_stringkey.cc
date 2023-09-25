#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int lines; cin>>lines;
  set<string> users;
  map<string,pair<int,set<string>>> used;
  for (string s; getline(cin,s);) if (s.length()){
    stringstream sst(s);
    string user,word; sst>>user;
    users.insert(user);
    while (sst>>word){
      used[word].second.insert(user);
      used[word].first--;
    }
  }
  vector<pair<int,string>> res;
  for (auto i: used)
    if (i.second.second.size()==users.size())
      res.emplace_back(i.second.first,i.first);
  if (res.empty()) cout<<"ALL CLEAR\n";
  sort(res.begin(),res.end());
  for (auto i: res)
    cout<<i.second<<endl;
}
