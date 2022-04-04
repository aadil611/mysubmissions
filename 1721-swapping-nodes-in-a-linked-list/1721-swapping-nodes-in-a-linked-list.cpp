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
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt=1;
        ListNode *temp=head,*left=head,*right=head;
        if(!head->next)
            return head;
        while(temp){
            if(cnt==k)
                left=temp;
            temp=temp->next;
            cnt++;
        }
        while(cnt>k+1){
            right=right->next;
            cnt--;
        }
        int helper=left->val;
        left->val=right->val;
        right->val=helper;
        
        return head;
    }
};