#include <iostream>
#include <sstream>
#include <map>
#include <set>
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
  for (auto i: used)
    if (i.second.second.size()==users.size())
      cout<<i.first<<endl;
}
