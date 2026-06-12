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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* temp;
        if (list1 == NULL) {
            return list2;
        } else if (list2 == NULL) {
            return list1;
        }
        
        if (list1->val <= list2->val) {
            temp = list1->next;
            head = list1;
            list1->next = NULL;
            list1 = temp;
        } else {
            temp = list2->next;
            head = list2;
            list2->next = NULL;
            list2 = temp;
        }

        ListNode* start=head;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp = list1->next;
                head->next = list1;
                list1->next = NULL;
                list1 = temp;
                head=head->next;
            } else {
                temp = list2->next;
                head->next = list2;
                list2->next = NULL;
                list2 = temp;
                head=head->next;
            }
        }

        if(list1 != NULL) {
            cout<<list1->val;
            head->next = list1;
        } else {
            cout<<list2->val<<" "<<head->val;
            head->next = list2;
        }

        return start;
    }
};
