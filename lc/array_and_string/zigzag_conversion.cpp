#include<iostream>
#include<string>

std::string convert(std::string s, int numRows) {
  std::string result;
  int l = (numRows-1)*2;
  if(l<1){
    return s;
  }
  int index1, index2;
  for(index1=0; index1<s.length(); index1 += l){
    result += s[index1];
  }
  for(int i=1; i<numRows-1; i++){
    index1 = i;
    index2 = l-i;
    while(index2<s.length()){
      result += s[index1];
      result += s[index2];
      index1 += l;
      index2 += l;
    }
    if(index1<s.length()){
      result += s[index1];
    }
  }
  for(index1=numRows-1; index1<s.length(); index1 += l){
    result += s[index1];
  }
  return result;
}

int main(){
  std::string result = convert("PAYPALISHIRING", 3);
  std::cout<<result<<std::endl;
}
