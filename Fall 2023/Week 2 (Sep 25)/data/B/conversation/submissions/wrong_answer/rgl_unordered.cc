#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
  int lines; cin>>lines;
  unordered_set<string> users;
  unordered_map<string,pair<int,unordered_set<string>>> used;
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
