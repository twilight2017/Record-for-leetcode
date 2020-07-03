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
   虽然解出来了，这个方法却没多好，完全是利用数学规律，只能下来继续学习改进了
   思想：每次检查两个节点，交换他们的值
   直至检索完所有链表节点，且不用开辟新的存储空间，只能说是空间利用率还算比较高吧
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //首先需要计算该链表的长度以规避特殊情况
        ListNode* p=head;
        int length=0;
        while(p){
            length++;
            p=p->next;
        }
        if(length<2) return head;
        else{
            ListNode* p2=head;//用于检索的索引指针
            ListNode* res=head;
            ListNode* help=res;
            while(p2&&p2->next){
                ListNode* cur=help;//找到当前的节点
                ListNode* chan=cur->next;
                int temp=0;
                temp=cur->val;
                cur->val=chan->val;
                chan->val=temp;
                help=chan->next;
                p2=(p2->next)->next;
        }
            return res;
        }
    }
};