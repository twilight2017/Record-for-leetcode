/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
 利用数学规律，得到了24题在普遍意义下的应用，可惜空间复杂度不好，新
 要求了一个很大很大的数组来存放需要进行倒叙排列的值
 这倒是顾此失彼了
 但网课里讲的方法也算是属实没有听懂
 功能函数check也不失为这种求解方法的灵魂所在了
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //新增加一个功能函数以应对求余时的情况
        //首先需要计算该链表的长度以规避特殊情况
        ListNode* p=head;
        int length=0;
        while(p){
            length++;
            p=p->next;
        }
        if(length<k) return head;
        else{
            ListNode* p2=head;//用于检索的索引指针
            ListNode* res=head;
            ListNode* help=res;
            ListNode* cur=help;//找到当前的节点
            int record[100000];
            for(int i=0;i<length;i++)
            {
                record[i]=0;
            }
            while(check(cur,k)){

                ListNode* num=cur;
                for(int i=0;i<k;i++)
                {
                    record[i]=num->val;
                    num=num->next;
                }
                for(int j=0;j<k;j++)
                {
                    cur->val=record[k-j-1];
                    cur=cur->next;
                }
        }
            return res;
        }
    }
    int check(ListNode* index,int k){
        int res=1;
            for(int i=0;i<k;i++)
            {
                if(!index) {
                    res=0;
                    break;
                }
                index=index->next;
            }
        return res;
    }
};