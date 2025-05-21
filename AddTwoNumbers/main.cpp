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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1Node = l1;
        ListNode* l2Node = l2;
        ListNode* resNode = nullptr;
        ListNode* currentNode = nullptr;
        int resValue = 0;

        for (; l1Node != nullptr && l2Node != nullptr; l1Node = l1Node->next, l2Node = l2Node->next) {
            resValue += l1Node->val + l2Node->val;
            ListNode* newNode = new ListNode(resValue % 10);

            if (!resNode) {
                resNode = newNode;
                currentNode = newNode;
            } else {
                currentNode->next = newNode;
                currentNode = newNode;
            }

            resValue /= 10;
        }

        if (l1Node == nullptr && l2Node != nullptr) {
            for (; l2Node != nullptr; l2Node = l2Node->next) {
                resValue += l2Node->val;
                ListNode* newNode = new ListNode(resValue % 10);

                if (!resNode) {
                    resNode = newNode;
                    currentNode = newNode;
                } else {
                    currentNode->next = newNode;
                    currentNode = newNode;
                }

                resValue /= 10;
            }
        } else if (l1Node != nullptr && l2Node == nullptr) {
            for (; l1Node != nullptr; l1Node = l1Node->next) {
                resValue += l1Node->val;
                ListNode* newNode = new ListNode(resValue % 10);

                if (!resNode) {
                    resNode = newNode;
                    currentNode = newNode;
                } else {
                    currentNode->next = newNode;
                    currentNode = newNode;
                }

                resValue /= 10;
            }
        }

        if (resValue > 0) {
            ListNode* newNode = new ListNode(resValue % 10);
            if (!resNode) {
                resNode = newNode;
                currentNode = newNode;
            } else {
                currentNode->next = newNode;
                currentNode = newNode;
            }
        }

        return resNode;
    }
};
