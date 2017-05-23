#include<vector>

int wiggleMaxLength(std::vector<int>& nums) {
  if(nums.empty()){
    return 0;
  }
  int iMaxLen = 1;
  int dMaxLen = 1;
  int flag = -1;
  for(int i=1; i<nums.size(); i++){
    if(nums[i] > nums[i-1] && flag != 0){
      iMaxLen = dMaxLen + 1;
      flag = 0;
    }
    else if(nums[i] < nums[i-1] && flag != 1){
      dMaxLen = iMaxLen + 1;
      flag = 1;
    }
  }
  return iMaxLen > dMaxLen ? iMaxLen : dMaxLen;
}
