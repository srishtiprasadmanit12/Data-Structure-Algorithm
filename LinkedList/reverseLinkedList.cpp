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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode*node = NULL;
     while(head){
        ListNode* temp = head->next;
        head->next=node;
        node = head;
        head=temp;
     }
     return node;
    }
};
/*

        1   2   3   4   5
node    h   t
            n

*/