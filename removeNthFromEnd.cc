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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
				int i = 0;
			ListNode *pre = head;
			ListNode *cur = head;
            if (n==1) {
                if (cur->next == NULL)
                    return NULL;
                while (cur->next->next) cur = cur->next;
                cur->next = NULL;
                return head;
            }
			
            while (i < n) {
				cur = cur->next;
				i++;
			}
            if (i == 1 && cur == NULL)
                return NULL;
                
			while (cur) {
				cur = cur->next;
				pre = pre->next;
			}
			    pre->val = pre->next->val;
		    	pre->next = pre->next->next;

			return head;
    }
};

int main(int argc, char **argv) {
	return 0;
}
