#include<iostream>
#include <climits>

int reverse(int x) {
  long num = 0;
  while(x!=0){
    num = num*10 + x%10;
    x /= 10;
  }
  return (num > INT_MAX || num < INT_MIN) ? 0 : num;
}

int main(){
  std::cout<<reverse(1534236469)<<std::endl;
  int num = 9646324351;
  if(num > INT_MAX){
    num = 0;
  }
  std::cout<<num<<std::endl;
  return 0;
}
