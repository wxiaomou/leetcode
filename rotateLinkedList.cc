/**
 * Definition for singly-linked list.
*/
#include <iostream>
#include <stddef.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
			if (!head || k == 0)
        		return head;
			int i = 0;
			ListNode *pre = head;
			ListNode *cur = head;
			while (i < k && cur != NULL) {
				cur = cur->next;
				i++;
			}
		

			if (!cur) {
				return rotateRight(head, k - i);
			}
            if (i < k) {
				return head;
			}

			while (cur->next) {
				pre = pre->next;
				cur = cur->next;
			}
			cur->next = head;
			head = pre->next;
			pre->next = NULL;
			return head;
    }
};

int main(int argc, char **argv) {
	return 0;
}
