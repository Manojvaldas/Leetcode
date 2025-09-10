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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;

        }
        return prev;

    }
    ListNode* getKThNode(ListNode* temp, int k) {
        k-=1;
        while(temp != NULL && k > 0) {
            k--;
            temp = temp->next;

        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {
            ListNode* kThNode = getKThNode(temp, k);
            if(kThNode == NULL) {
                if(prev) {
                    prev->next = temp;
                }
                break;
            }
            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head) {
                head = kThNode;
            } else {

                prev->next = kThNode;
                
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};