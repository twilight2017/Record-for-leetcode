/*
时间复杂度：O(n)
空间复杂度：O(n)
基本思路是采用了一个辅助数组，根据下标标记当前数字是否已经出现过
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
    int length = nums.size();
    bool flag[100000];
    if(length==0)
      return -1;
    else{
        int i=0;
        for(i=0;i<length;i++){
            flag[i]=false;
        }
        for(i=0;i<length;i++){
            int j=nums[i];
            if(flag[j]==false) flag[j]=true;
            else break;
        }
        return nums[i];
    }
    }
};