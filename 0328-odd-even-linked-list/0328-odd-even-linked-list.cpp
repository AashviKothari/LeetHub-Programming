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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddhead=NULL, *oddtail=NULL, *evenhead=NULL, *eventail=NULL;
        int count =1;
        while(head!=NULL){
            if(count%2==0){
                if(evenhead==NULL){
                    evenhead=eventail=head;
                    head=head->next;
                }
                else{
                    eventail->next=head;
                    eventail=eventail->next;
                    head=head->next;
                }
            }
            else{
               if(oddhead==NULL){
                    oddhead=oddtail=head;
                    head=head->next;
                }
                else{
                    oddtail->next=head;
                    oddtail=oddtail->next;
                    head=head->next;
                } 
            }
            count++;
        } 

        if(oddhead==NULL){
            return evenhead;
        }

        if(evenhead==NULL){
            return oddhead;
        }

        eventail->next=NULL;
        oddtail->next=evenhead;

        return oddhead;
    }
};