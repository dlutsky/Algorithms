#include<iostream>
#include<climits>
#include<string>
#include<ctype.h>

int atoi(std::string str) {
  long num = 0;
  bool isPositive = true;
  int pos = 0;
  while(str[pos]==' '){
    pos++;
  }
  if(str[pos] == '+')
    pos++;
  if(str[pos] == '-'){
    isPositive = false;
    pos++;
  }
  while(pos<str.length() && isdigit(str[pos])){
    num = num * 10 + str[pos] - '0';
    if(num > INT_MAX){
      return isPositive ? INT_MAX : INT_MIN;
    }
    pos++;
  }
  return isPositive ? num : 0-num;
}

int main(){
  std::cout<<atoi("2147483648")<<std::endl;
  return 0;
}
