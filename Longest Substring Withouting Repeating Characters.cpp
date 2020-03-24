class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //用滑动窗口法求解这道题目是最符合人的思维方式的
        int begin=0,end=0;//设置左窗口和右窗口的初始值
        int maxLength=end-begin+1;
        int currentLength=0;
        int j=0;
        if(s.length()<=0) maxLength=0;
        if(s.length()>0){
        for(;end<s.length();end++){
            for(j=begin;j<end;j++)
            {
                if(s[j]==s[end]) break;
            }
            if(j==end){//当前检索不出现重复的情况
                currentLength=end-begin+1;
            }else{
                begin=j+1;//出现重复字符，左窗口应向右滑动
                currentLength=end-begin+1;
            }
            if(currentLength>maxLength) maxLength=currentLength;
        }
     }
        return maxLength;
    }
};