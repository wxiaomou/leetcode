#include<iostream>
#include<stddef>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      if (!l1 || !l2)
				 return NULL;
			ListNode *it1 = l1;
			ListNode *it2 = l2;
			bool carry = false;
			ListNode *ret = NULL;
			ListNode *cur = NULL;
			while (it1 || it2) {
				int L1 = it1 ? it1->val : 0;
				int L2 = it2 ? it2->val : 0;
				ListNode * tmp = new ListNode(NULL);
				int sum = carry ? L1 + L2 + 1 : L1 + L2;
				if (sum > 9) {
					carry = true;
					tmp->val = sum % 10;
				} else {
					tmp->val = sum;
					carry = false;
				}
				if (!ret) {
					ret = tmp;
					cur = ret;
				}
				else { 
					cur->next = tmp;
					cur = cur->next;
				}
				it1 = it1 ? it1->next : NULL;
				it2 = it2 ? it2->next : NULL;
			}

			if (carry != 0) {
				ListNode *tmp = new ListNode(carry);
				cur->next = tmp;
			}

			return ret;
    }
};
