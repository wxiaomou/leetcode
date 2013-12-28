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
	ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next || !k) return head;
        ListNode *pre = head;
        ListNode *cur = head;
        
        int i = 0;
        while (i < k) {
            if (!cur)
                cur = head->next;
            else 
                cur = cur->next;
            i++;
            if (i == k && !cur) return head; // if k larger than the linklist length, like a mod function
        }
        cur = cur->next;
        while (cur) {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode *post = pre->next;
        cur = post;
        pre->next = NULL;
        
        while (cur->next) 
            cur = cur->next;
        cur->next = head;
        return post;
    }
    //recursive way
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
		
            //if k larger than the linklist length then divide and concur
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
