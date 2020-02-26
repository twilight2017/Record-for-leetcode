class Solution {
public:
    int fun(int x,int y){//编写函数用于计算数的次方
        int result=1;
        for(int i=1;i<=y;i++){
            result=result*x;
        }
        return result;
    }
    //用于求绝对值的函数
    long absolute(long x){
        if(x>=0) return x;
        else return -x;
    }
    int reverse(int x) {
        bool judge=true;
        int count=0;//计数器，用于记录数串的位长
        for(int i=0;;i++){
            if (i==10){
                if(absolute(x)%fun(10,1)>2){
                    return 0;
                }
                else {
                    break;
                }
            }
            if(absolute(x/fun(10,i))<1){
                break;
            }
            else count++;
        } 
        int res[100];//用于存储反序操作后得到的各位数字
        int index=0;
        for(int i=count-1;i>=0;i--){
            res[index]=x/fun(10,i);
            x=x%fun(10,i);
            index++;
        }
        //以下操作用于返回正确的结果
        long sum=0;
        for(int i=count-1;i>=0;i--){
            sum+=res[i]*fun(10,i);
        }
        if (sum>2147483647||sum<-2147483648) return 0;
        else return sum;
    }

};