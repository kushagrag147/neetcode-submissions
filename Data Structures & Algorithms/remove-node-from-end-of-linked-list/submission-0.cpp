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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first=head, *second=head, *prev=nullptr;
        int k=1;

        while(k<=n) {
            second=second->next;
            k++;
        }

        while(second) {
            prev=first;
            first=first->next;
            second=second->next;
        }

        if (prev == nullptr) {
            head=head->next;
        } else {
            prev->next=first->next;
        }

        return head;
    }
};
