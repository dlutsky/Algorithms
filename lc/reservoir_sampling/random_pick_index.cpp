#include<vector>
#include<cstdlib>
#include<ctime>

class Solution {
private:
    std::vector<int> nums;
public:
    Solution(std::vector<int> nums) {
        this->nums = nums;
        srand(time(NULL));
    }

    int pick(int target) {
        int index = -1;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                count++;
                if(index == -1){
                    index = i;
                }
                else if(rand()%count == 1){
                    index = i;
                }
            }
        }
        return index;
    }
};
