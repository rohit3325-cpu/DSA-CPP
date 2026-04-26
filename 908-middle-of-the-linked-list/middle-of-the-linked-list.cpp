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
    int getlen(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            count+=1;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int len=getlen(head);
        int i=0;
        ListNode* temp=head;
        while(i<len){
            if(i==len/2){
                break;
            }
            temp=temp->next;
            i++;
        }
        
        
        return temp;
    }
};