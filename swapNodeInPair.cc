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
	//iterative way
	ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *ret = NULL;
        ListNode *cur = head;
        ListNode *cur1 = NULL;
        ListNode *post = head->next;
        
        while (cur && post) {
            ListNode *tmp = post->next;
            post->next = cur;
            cur->next = tmp;
            if (cur1)
                cur1->next = post;
            cur1 = cur;
            if (!ret) {
                ret = post;
            } 
            cur = cur->next;
            if (cur)
                post = cur->next;
        }
        return ret;
    }
    //recursive way
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
