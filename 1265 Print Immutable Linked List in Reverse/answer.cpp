class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* const head) {
        if (head){
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
};