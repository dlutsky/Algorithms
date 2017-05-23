#include<string>

bool isSubsequence(std::string s, std::string t) {
  int j=0;
  for(int i=0; i<t.length(); i++){
    if(s[j] == t[i]){
      j++;
    }
  }
  return j==s.size();
}
