#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *tmp1 = head1;
    SinglyLinkedListNode *tmp1_back = nullptr;
    SinglyLinkedListNode *tmp2 = head2;
    
    while (tmp1 != nullptr) {
        if (tmp2 != nullptr) {
            if (tmp1->data <= tmp2->data) {
                tmp1_back = tmp1;
                tmp1 = tmp1->next;
            }
            else {
                if (tmp1_back != nullptr) {
                    tmp1_back->next = tmp2;
                    tmp2 = tmp2->next;
                    tmp1_back->next->next = tmp1;
                    tmp1_back = tmp1_back->next;
                }
                else {
                    head1 = tmp2;
                    tmp2 = tmp2->next;
                    head1->next = tmp1;
                    tmp1_back = head1;
                }
            }
        }
        else {
            tmp1_back = tmp1;
            tmp1 = tmp1->next;
        }
    }
    
    if (tmp2 != nullptr) {
        tmp1_back->next = tmp2;
    }
    
    return head1;
}

int main()