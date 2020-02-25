class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            vector<int>res;//定义一个容器用于存放结果集
            int len =nums.size();
            for(int i=0;i<len;i++){
                for(int j=i+1;j<len;j++){
                    if(nums[i]+nums[j]==target){
                        res.push_back(i);
                        res.push_back(j);
                        break;
                    }
          } 
       }
        return res;
  }
};