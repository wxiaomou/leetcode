/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
class Solution {
public:
    map<RandomListNode *, RandomListNode *> hash;
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if (!head) return NULL;
        if (hash.find(head) != hash.end())
            return hash.find(head)->second;
        RandomListNode *ret = new RandomListNode(head->label);
        hash.insert(pair<RandomListNode *, RandomListNode *>(head, ret));
        if (head->next) 
            ret->next = copyRandomList(head->next);
        if (head->random)
            ret->random = copyRandomList(head->random);
        return ret;
    }
};