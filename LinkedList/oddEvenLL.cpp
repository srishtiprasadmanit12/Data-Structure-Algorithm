class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if(!head ||!head->next||!head->next->next){
        return head;
      }

      ListNode* odd = head;
      ListNode* even = head->next;
      ListNode* even_start = head->next;

      while(odd->next && even->next){
        odd->next = even->next; // collect all odds
        even->next = odd->next->next; //collect all even(since odd->next has even->next)
        odd=odd->next;
        even=even->next;
      }
        odd->next = even_start;
        return head;
    }
};
