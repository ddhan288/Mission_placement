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
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater_head=new ListNode();
        ListNode *smaller_head=new ListNode();
        
        ListNode *small=smaller_head;
        ListNode *great=greater_head;
        
        ListNode *temp=head;
        
        while(temp!=NULL)
        {
           if(temp->val<x)
           {
               small->next=temp;
               small=small->next;
           }
            else{
                great->next=temp;
                great=great->next;
            }
            temp=temp->next;
        }
        
        small->next=greater_head->next;
        great->next=NULL;
        return smaller_head->next;

    }
};