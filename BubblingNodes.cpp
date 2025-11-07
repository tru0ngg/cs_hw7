// This file is called BubblingNodes.cpp
#include <iostream>
using std::cout, std::cin, std::endl;

struct Node {
    int value = -1;
    Node* next = nullptr;
};

bool is_less_than(int x, int y){
        if (x % 2 == 0 && y % 2 != 0){
                return true;
        } else if (x % 2 != 0 && y % 2 ==0){
                return false;
        } else {
                return x < y;
        }
}

void bubble_sort_special(Node* head) {
    // for you to fill in
        Node* prt = head;
        int N = 0;
        while ( prt != nullptr && prt->next != nullptr){
                prt = prt->next;
                N++;
        }
        for (int i = 0; i < N-1; i++){
                Node* current = head;
                while (current != nullptr && current->next != nullptr){
                        if (!is_less_than(current->value, current->next->value)){
                                int current_val = current->value;
                                int next_val = current->next->value;

                                current->value = next_val;
                                current->next->value = current_val;

                                if (current_val > next_val){
                                        cout << "Swap " << current_val << " with " << next_val << endl;
                                } else {
                                        cout << "Swap " << current_val << " with " << current_val << endl;
                                }
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
