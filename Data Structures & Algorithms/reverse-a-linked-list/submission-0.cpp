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
        ListNode *temp, *prevNode, *itr=head;

        prevNode=NULL;

        while(itr!=NULL) {
            temp=itr->next;
            itr->next=prevNode;

            prevNode=itr;
            itr=temp;
        }

        return prevNode;
    }
};
