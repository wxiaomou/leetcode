/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stddef.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct PariComparator {
	bool operator() (const pair<int, int> &p1, const pair<int, int>&p2) {
		return p1.first > p2.first;
	}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
			ListNode *head = NULL;
			ListNode *tail = head;
			if (!lists.size())
				return head;
			
			priority_queue< pair<int, int>, vector< pair<int, int> >, PariComparator> heap;

			for (int i = 0; i < lists.size(); ++i) {
				if (lists[i]) {
					heap.push(pair<int, int> (lists[i]->val, i));
				}
			}

			while (!heap.empty()) {
				pair<int, int> tmp = heap.top();
				heap.pop();
				if (lists[tmp.second]) {
					ListNode *tmp1 = new ListNode(tmp.first);
					if (!head) {
						head = tmp1;
						tail = head;
					} else {
						tail->next = tmp1;
						tail = tail->next;
					}

					lists[tmp.second] = lists[tmp.second]->next;
					if (lists[tmp.second]) {
						heap.push(pair<int, int> (lists[tmp.second]->val, tmp.second));
					}
				}

			}
			return head;
    }
};
int main(int argc, char **argv) {
	return 0;
}
