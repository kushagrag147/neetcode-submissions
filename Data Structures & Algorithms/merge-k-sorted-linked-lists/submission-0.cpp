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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeKListsDivideNdConquer(lists, 0, lists.size()-1);
    }

    ListNode* mergeKListsDivideNdConquer(vector<ListNode*>& lists, int start, int end) {
        if (start==end) {
            return lists[start];
        }

        if (end-start==1) {
            return mergeTwoLists(lists[start], lists[end]);
        }

        int mid = start + (end-start)/2;

        return mergeTwoLists(mergeKListsDivideNdConquer(lists, start, mid), mergeKListsDivideNdConquer(lists, mid+1, end));
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
