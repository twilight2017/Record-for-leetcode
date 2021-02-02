/*
最基本的方法是使用暴力递归，但这样会导致程序的时间复杂度高达O(mn)
显然不符合优秀的程序设计习惯
可以利用数组每列元素递增的特性，基于比较，使用二分法求解
反思：使用双重循环时的break语句仅能跳出当前循环，不如使用return
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
     //首先锁定目标元素所在的列
     int i=0;
     int n=matrix.size();//统计行数
     if(n==0) return false;
     int m=matrix[0].size();//统计列数
     //cout<<m<<n;
     if(n==0||m==0) return false;//参数非法 直接返回
     for(i=m-1;i>=0;){
       if(matrix[0][i]==target) return true;//匹配成功
       if(matrix[0][i]<target) break;//成功锁定搜索范围
       else i--;
     }
     //cout<<i;
     if(i<0) return false;//所有元素均不符合要求
     int j=0;
     for(;i>=0;i--)
       for(j=0;j<n;j++){
         if(matrix[j][i]==target) return true;
       }
      return false;//查找失败
    }
};