#include <iostream>
#include "headers/node.h"

using namespace std;

Node * mergeDLL(Node * head);

int main() {
    cout << "Hello World" << endl;
}

Node * mergeDDL(Node * head) {
    Node * merged_list = head;
    Node * temp_head = head;

    while(temp_head) {
        if(temp_head->next) {
            mergeDDL(temp_head);
        }
        else {
            merged_list->next = temp_head->next;
        }
        
        temp_head = temp_head->next;
    }
}
