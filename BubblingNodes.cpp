// This file is called BubblingNodes.cpp
#include <iostream>
using std::cout, std::cin, std::endl;

struct Node {
    int value = -1;
    Node* next = nullptr;
};

bool is_less_than(int x, int y){
        if (x % 2 != 0 && y % 2 == 0){
                return true;
        } else if (x % 2 == 0 && y % 2 !=0){
                return false;
        } else {
                return x > y;
        }
}

void bubble_sort_special(Node* head) {
    // for you to fill in
        bool swapped = true;
        while (swapped) {
                swapped = false;
                Node* current = head;
                while (current->next != nullptr){
                        if (is_less_than(current->value, current->next->value)){
                                int temp = current->value;
                                current->value = current->next->value;
                                current->next->value = temp;

                                cout << "Swap " << current->next->value << " with " << current->value << endl;
                                swapped = true;
                        }
                        current = current->next;
                }
        }
}

int main() {
    int N;
    cin >> N;
    Node* head = new Node;
    cin >> head->value;
    Node* tail = head;
    for (int i = 1; i < N; i++) {
        Node* new_node = new Node;
        cin >> new_node->value;
        tail->next = new_node;
        tail = new_node;
    }
    bubble_sort_special(head);
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        Node* next = current->next;
        delete current;
        current = next;
    }
    cout << endl;
    return 0;
}
