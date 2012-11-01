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
    ListNode *swapPairs(ListNode *head) {
			if (!head || !head->next)
				return head;

			ListNode *pre = NULL;
			ListNode *cur = head;
			ListNode *post = head->next;
		
			cur->next = pre;
			pre = cur;
			cur = post;
			post = post->next;
			cur->next = pre;
			head = cur;
			pre->next = swapPairs(post);
			return head;
			//post = post->next;
			

    }
};

int main(int argc, char **argv) {
	return 0;
}
