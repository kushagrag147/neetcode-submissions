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
    void reorderList(ListNode* head) {
        ListNode *middle=head, *fast=nullptr, *second;
        if (head && head->next) {
            fast = head->next->next;
        }
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            middle = middle->next;
        }
        second = middle->next;
        middle->next = nullptr;

        second = reverseList(second);
        // printNode(second);
        // printNode(head);

        head = alternateJoin(head, second);
    }

    void printNode(ListNode* head) {
        while(head) {
            cout<<head->val<<" ";
            head=head->next;
        }

        cout<<"\n";
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *curr= head;
        ListNode *prev=nullptr;

        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

    ListNode* alternateJoin(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        list1->next = alternateJoin(list2, list1->next);

        return list1;
    }

};
