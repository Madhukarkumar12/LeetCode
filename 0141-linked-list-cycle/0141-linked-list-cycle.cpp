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
    bool hasCycle(ListNode *head) {
        // unordered_map<ListNode*,int>st;
        // ListNode* temp=head;
        // while(temp != NULL){
        //     if(st.find(temp) != st.end()){
        //         return true;
        //     }
        //     st[temp]=1;
        //     temp=temp->next;
        // }
        // return false;


        // floyd detection technique.....
        
        if(head==NULL || head->next==NULL) return false;
        ListNode* fast=head;
        ListNode* slow=head;
        while(slow != NULL && fast != NULL){
            fast=fast->next;
            if(fast != NULL)  fast=fast->next;
           
            slow=slow->next;
            if(fast == slow) return true;
        }
        return false;

    }
};