#include <iostream>
#include <stddef.h>
using namespace std;

struct Node {
	int val;
	Node *next;
};

class List {
public:
	Node *insert(Node *head, int val) {
		if (!head) {
			head = new Node;
			head->val = val;
			head->next = head;
			return head;
		}
		if (val < head->val) {
			Node *tmp = new Node;
			tmp->val = head->val;
			tmp->next = head->next;
			head->val = val;
			head->next = tmp;
			return head;
		}
		
		Node *tmp = head;
		while(true) {
			if (tmp->next->val > val) {
				Node *tmp1 = new Node;
				tmp1->val = val;
				tmp1->next = tmp->next;
				tmp->next = tmp1;
				return head;
			}
			tmp = tmp->next;
			if (tmp->next == head)
				break;
		}

		if (tmp->next == head) {
			Node *tmp1 = new Node;
			tmp1->val = val;
			tmp1->next = head;
			tmp->next = tmp1;
		}

		return head;
	}

	void print(Node *head) {
		if (!head)
			return;
		Node *tmp = head;
		cout << head->val << " ";
		while (tmp->next != head) {
			tmp = tmp->next;
			cout << tmp->val << " ";
		}
		cout << endl;
	}

};

int main(int argc, char **argv) {
	List sol;
	Node *head = NULL;
	head = sol.insert(head, 5);
	sol.print(head);
	head = sol.insert(head, 8);
	sol.print(head);
	head = sol.insert(head, 3);
	sol.print(head);
	head = sol.insert(head, 6);
	sol.print(head);
}
