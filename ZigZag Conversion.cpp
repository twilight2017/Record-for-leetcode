/*
   暴力拆解法，全靠自己找出其中的数学规律，没有什么技巧可言
   还是需要看看别人的优秀算法
   Runtime:faster than 5.23%
   Memory Usage:less than 100%
*/
class Solution {
public:
    int Max_size=1000;
    string convert(string s, int numRows) {
        char res[Max_size][Max_size];
        for(int i=0;i<Max_size;i++)
            for(int j=0;j<Max_size;j++)
                res[i][j]='0';
        int len=s.length();//记录输入字符串的长度
        int i=numRows;//行
        int j=0;//列数，是用数学归纳法总结得到的
        if(i==1) return s;
        else{
        for(int col=1;col<=len;){
            if(j%(i-1)==0){
                col+=i;
                j+=1;
            }
            else{
                col+=1;
                j+=1;
            }
        }
        int index=0;//用于字符串的下标检索
        for(int k=0;k<j;k++)
        {
            if(k%(i-1)==0){
            for(int m=0;m<i;m++){
                     res[m][k]=s[index];
                     index++;
                if(index==len) break;
                 }
            }
            else{
                int pos=k%(i-1);
                res[i-1-pos][k]=s[index];
                index++;
                if(index==len) break;
            }
         }
        string so;
        for(int k=0;k<i;k++)
            for(int m=0;m<j;m++)
            {
                if(res[k][m]!='0'&&res[k][m]!=' '){
                  so+=res[k][m];
                }
            }
        return so;
        }
    }
};