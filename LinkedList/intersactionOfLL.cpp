/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //length of both LL
    int n1=0,n2=0;
    ListNode*temp1=headA;
    ListNode* temp2=headB;
    while(temp1){
        n1++;
        temp1=temp1->next;
    }
    while(temp2){
        n2++;
        temp2=temp2->next;
    }
    //bring temp1,temp2 back to their head
    temp1=headA;
    temp2=headB;
    //traversse bigger LL reaching to pointer same as length 
    while(n1>n2){
     n1--;
     temp1=temp1->next;
    }
    while(n2>n1){
        n2--;
        temp2=temp2->next;
    }
    //Traverse both LL together to find same element  
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    } 
    return temp1;
    }
};