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
    int getDecimalValue(ListNode* head) {
        stack<int>stk;
        ListNode* temp = head;
        // Push all elements in stack , since we need elemnts in reverse order for doing operation
        while(temp){
            stk.push(temp->val);
            temp=temp->next;
        }
        int cnt = 0;
        int res=0;
        while(!stk.empty()){
            int x = stk.top();
            stk.pop();
            res =res+ x * pow(2,cnt);
            cnt++;
        }
        return res;

    }
};

/* 

101
1*2^0 + 0*2^1 + 1*2^2 = 1+0+4 = 5 

*/