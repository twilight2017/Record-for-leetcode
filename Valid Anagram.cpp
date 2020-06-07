/*
  好的算法是程序设计成功的一半
  第一思路：两个数组，长度都是26，记录每个字母的个数，最后比较两个数组是否一样
  第二思路（来自网课学习的成果）
  一个数组，长度为26，对字符串s,对应字母位+1，对字符串t,对应字母位-1
  最后比较这个数组是不是一个全0 数组，这思路真的牛气
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1=s.length(); //length of s
        int l2=t.length(); //length of t
        if(l1!=l2){
            return false;
        }
        else{
            int res[26]; //result array
            bool flag = true; //judge
            for(int m=0;m<26;m++)
            {
                res[m]=0;
            }
            for(int i=0;i<l1;i++){
                  res[int(s[i])-97]++;
            }
            for(int j=0;j<l2;j++){
                res[int(t[j])-97]--;
            }
            for(int k=0;k<26;k++){
                if(res[k]!=0){
                    flag = false;
                    break;
            }
                 }
            return flag;
           
    }
    }
};