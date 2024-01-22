#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int main(){
  int lines; cin>>lines;
  map<string,int> users;
  map<string,pair<int,set<int>>> used;
  for (string s; getline(cin,s);) if (s.length()){
    stringstream sst(s);
    string user,word; sst>>user;
    int uid=(users[user]?users[user]:users[user]=users.size());
    while (sst>>word){
      used[word].second.insert(uid);
      used[word].first--;
    }
  }
  int any=0;
  for (auto i: used)
    if (i.second.second.size()==users.size())
      cout<<i.first<<endl, ++any;
  if (not any) cout<<"ALL CLEAR\n";
}
