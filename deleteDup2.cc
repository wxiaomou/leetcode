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
    ListNode *deleteDuplicates(ListNode *head) {
			if (!head)
    			return NULL;
			if (!head->next)
				return head;

			ListNode *pre = head;
			ListNode *cur = head->next;
			int count = 0;
			bool beginWithDup = false;
			while (cur) {
				if (pre->val == cur->val) {
					if (pre == head)
						beginWithDup = true;
					cur = cur->next;
					count ++;
				} else {
					if (beginWithDup) {
						head = cur;
						pre = head;
                        cur = cur->next;
						beginWithDup = false;
					}	else if (count){
						pre->val = cur->val;
						pre->next = cur->next;
						cur = cur->next;
					} else {
						cur = cur->next;
                        pre = pre->next;
                    }
					count = 0;
				}
			}
            if (beginWithDup)
    		    return NULL;
            if (count) {
                cur = head;
                while (cur->next != pre) cur = cur->next; 
                cur->next = NULL;
            }
         
            //else
            return head;
		}
};

int main (int argc, char **argv) {
	return 0;
}
