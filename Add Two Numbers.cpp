/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}  //带参数初始化的构造函数
 * };
 */

class Solution {
public:
    void Insert_LinkList(ListNode* l,int value){
    ListNode* new1=new ListNode(value);
    l->next=new1;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1=0,size2=0;//记录两个链表的长度
        ListNode* p1=new ListNode(0);
        p1=l1;//为了方便遍历且不丢失链表1头节点的指针
        ListNode* p2=new ListNode(0);
        p2=l2;
        ListNode* head=new ListNode(0);
        int con=0;//记录进位的参数
        int sum=l1->val+l2->val+con;
        int result=sum%10;//修改要插入的数据
        con=sum/10;//修改进位信号
        head->val=result;
        l1=l1->next;
        l2=l2->next;
        while(p1!=NULL){
            size1++;
            p1=p1->next;
        }
        free(p1);
        while(p2!=NULL){
            size2++;
            p2=p2->next;
        }
        free(p2);
        if(size1==size2){
            ListNode *l=head;
            for(int i=1;i<size1;i++){
                sum=l1->val+l2->val+con;
                result=sum%10;//修改要插入的数据
                con=sum/10;//修改进位信号
                Insert_LinkList(l,result);
                l=l->next;
                l1=l1->next;
                l2=l2->next;
            }
            if(con==1){//仍存在向高位的一位进位
                Insert_LinkList(l,1);
                l=l->next;
            }
        }else if(size1<size2){
            ListNode *l=head;
            for(int i=1;i<size1;i++){
               sum=l1->val+l2->val+con;
                result=sum%10;//修改要插入的数据
                con=sum/10;//修改进位信号
                Insert_LinkList(l,result);
                l=l->next; 
                l1=l1->next;
                l2=l2->next;
            }
            for(int j=size1;j<size2;j++){
                sum=l2->val+con;
                result=sum%10;//修改要插入的数据
                con=sum/10;//修改进位信号
                Insert_LinkList(l,result);
                l=l->next; 
                l2=l2->next;
            }
            if(con==1){//仍存在向高位的一位进位
                Insert_LinkList(l,1);
                l=l->next;
            }
        }else{  //size1大于size2的情况
            ListNode *l=head;
            for(int i=1;i<size2;i++){
                sum=l1->val+l2->val+con;
                result=sum%10;//修改要插入的数据
                con=sum/10;//修改进位信号
                Insert_LinkList(l,result);
                l=l->next; 
                l1=l1->next;
                l2=l2->next;
            }
            for(int j=size2;j<size1;j++){
                sum=l1->val+con;
                result=sum%10;//修改要插入的数据
                con=sum/10;//修改进位信号
                Insert_LinkList(l,result);
                l=l->next; 
                l1=l1->next;
            }
            if(con==1){//仍存在向高位的一位进位
                Insert_LinkList(l,1);
                l=l->next;
            }
        //free(new1);
        }
        return head;
    }
};