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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {


        int temp=0;
        ListNode* temptr=list1;
        while(temp<a-1){
            temptr=temptr->next;
            temp++;
        }


        int temp2=0;
        ListNode* temptr2=list1;
        while(temp2<b){
            temp2++;
            temptr2=temptr2->next;
        }

        cout<<temptr->val<<" "<<temptr2->val;
        

        ListNode* temptr3=list2;

        while(temptr3->next!=NULL){
            temptr3=temptr3->next;
        }

        temptr->next=list2;
        temptr3->next=temptr2->next;
        
        return list1;
    }
};