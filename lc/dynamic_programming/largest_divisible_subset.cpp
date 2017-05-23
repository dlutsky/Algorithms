#include<vector>
#include<algorithm>
#include<string.h>

std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
  if(nums.empty()){
    return std::vector<int>();
  }
  std::sort(nums.begin(), nums.end());
  int parent[nums.size()];
  memset(parent, -1, sizeof(parent));
  int count[nums.size()];
  memset(count, 0, sizeof(count));
  int maxCount = 0;
  int maxIndex = 0;
  for(int i=0; i<nums.size(); i++){
    count[i] = 1;
    for(int j=i-1; j>=0; j--){
      if(nums[i]%nums[j] == 0){
        if(count[j]>=count[i]){
          parent[i] = j;
          count[i] = count[j] + 1;
        }
        if(count[i]>maxCount){
          maxCount = count[i];
          maxIndex = i;
        }
      }
    }
  }
  std::vector<int> res;
  int index = maxIndex;
  while(index != -1){
    res.push_back(nums[index]);
    index = parent[index];
  }
  return res;
}
