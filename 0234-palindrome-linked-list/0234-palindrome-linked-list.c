/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
if (!head || !head->next) return true;

    // 1. Find middle
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse second half
    struct ListNode* secondHalf = reverseList(slow);

    // 3. Compare halves
    struct ListNode* firstHalf = head;
    struct ListNode* temp = secondHalf;
    while (temp) {
        if (firstHalf->val != temp->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return true;    
}