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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next== NULL|| k==0){
            return head;
        }

        //find length
        int length=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
            length++;
        }
        tail->next=head;

        k=k%length;

        int steptonewtail=length-k;
        ListNode* newtail=head;
        for(int i=1;i<steptonewtail;i++){
            newtail=newtail->next;
        }

        ListNode* newhead=newtail->next;
        newtail->next=NULL;

        return newhead;

    }
};