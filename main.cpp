#include <iostream>
#include <string>
#include "headers/node.h"

using namespace std;

string buildTabs(int n);
void buildList(Node *& head);
void traverseList(Node *& head, int num_of_tabs);
void traverseFlatList(Node *& head);

void appendEndOfLevel(Node * head_level, Node * child_node);
void flattenList(Node *& head);

int main() {
    Node * head;
    cout << "============== ORIGINAL LIST ==============" << endl;
    buildList(head);
    traverseList(head, 0);

    cout << "============== FLATTENED LIST ==============" << endl;
    flattenList(head);
    traverseFlatList(head);

    
}


void traverseList(Node *& head, int num_of_tabs) {
    Node * traverse_elem = new Node;
    traverse_elem = head;
    string tabs = buildTabs(num_of_tabs);

    while(traverse_elem) {
        cout << tabs 
             << "Elem Data: " 
             << traverse_elem->data 
             << endl;

        if(traverse_elem->child)
            traverseList(traverse_elem->child,++num_of_tabs);

        traverse_elem = traverse_elem->next;
    }

}

void traverseFlatList(Node *& head) {
    Node * traverse_elem = new Node;
    traverse_elem = head;

    while(traverse_elem) {
        cout << "Elem Data: " 
             << traverse_elem->data 
             << endl;

        traverse_elem = traverse_elem->next;
    }
}

string buildTabs(int n){
    string tabs = "";

    for(int i = 0; i < n; i++){
        tabs += "    ";
    }

    return tabs;
}

void buildList(Node *& head) {
    Node * n1 = new Node;
    Node * n2 = new Node;
    Node * n3 = new Node;
    Node * n4 = new Node;
    Node * n5 = new Node;
    Node * n6 = new Node;
    Node * n7 = new Node;
    Node * n8 = new Node;
    Node * n9 = new Node;
    Node * n10 = new Node;
    Node * n11 = new Node;
    Node * n12 = new Node;
    Node * n13 = new Node;
    Node * n14 = new Node;
    Node * n15 = new Node;
    Node * n16 = new Node;
    Node * n17 = new Node;

    n1->data = 5;
    n2->data = 33;
    n3->data = 17;
    n4->data = 2;
    n5->data = 1;
    n6->data = 6;
    n7->data = 25;
    n8->data = 6;
    n9->data = 2;
    n10->data = 7;
    n11->data = 8;
    n12->data = 9;
    n13->data = 12;
    n14->data = 5;
    n15->data = 7;
    n16->data = 21;
    n17->data = 3;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    n6->next = n7;
    n7->next = n8;
    n8->next = NULL;
    n9->next = n10;
    n10->next = NULL;
    n11->next = NULL;
    n12->next = NULL;
    n13->next = n14;
    n14->next = NULL;
    n15->next = NULL;
    n16->next = n17;
    n17->next = NULL;

    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n2;
    n5->prev = n4;
    n6->prev = NULL;
    n7->prev = n6;
    n8->prev = n7;
    n9->prev = NULL;
    n10->prev = n9;
    n11->prev = NULL;
    n12->prev = NULL;
    n13->prev = NULL;
    n14->prev = n13;
    n15->prev = NULL;
    n16->prev = NULL;
    n17->prev = n16;

    n1->child = n6;
    n2->child = NULL;
    n3->child = NULL;
    n4->child = n9;
    n5->child = NULL;
    n6->child = NULL;
    n7->child = n11;
    n8->child = n12;
    n9->child = n13;
    n10->child = NULL;
    n11->child = NULL;
    n12->child = n15;
    n13->child = n16;
    n14->child = NULL;
    n15->child = NULL;
    n16->child = NULL;
    n17->child = NULL;

    head = n1;

}

void appendEndOfLevel(Node * head_level, Node * child_node) {

    //cout << "\tHead Data: " << head_level->data << endl;
    //cout << "\tChild Data: " << child_node->data << endl;

    while(head_level) {
        if(!head_level->next) {
            //cout << "Last Elem in Head List: " << head_level->data << endl;
            head_level->next = child_node;
            break;
        }

        head_level = head_level->next;
    }
    
}

void flattenList(Node *& head) {
    Node * head_elems = head;
    Node * child_elems;

    while(head_elems) {
        //cout << "Data: " << head_elems->data << endl;

        if(head_elems->child) {
            //cout << "\tCHILD FOUND" << endl;
            appendEndOfLevel(head_elems, head_elems->child);
        }

        head_elems = head_elems->next;
    }

}
