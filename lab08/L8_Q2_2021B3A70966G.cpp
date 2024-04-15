#include <vector>
#include "Node.h"
using namespace std;

//////////////////////////////////////////////////////////////////////
// NODE FORMAT
//
// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
//     Node(int value) : data(value), prev(nullptr), next(nullptr) {}
// };
//////////////////////////////////////////////////////////////////////



Node* solve(Node* head1, Node* head2) {
    long long int num1=0,k=1;
    Node* iter = head1;
    while(iter != nullptr){
        num1 += iter->data * k;
        k *= 10;
        iter = iter->next;
    }

    long long int num2=0;
    k=1;
    iter = head2;
    while(iter != nullptr){
        num2 += iter->data * k;
        k *= 10;
        iter = iter->next;
    }

    Node* head = nullptr;
    
    long long int mul = num1*num2;
    while(mul>0){
        Node* temp = new Node(mul % 10);
        mul /= 10;
        Node* prev = head;
        if (head!=nullptr){
            head->next = temp;
        }
        temp->prev = head;
        head = temp;
    }

    return head;

    // Node* head = nullptr;
    // Node* start = head;
    // Node* iter2 = head2;
    // while(iter2!=nullptr){
    //     int carry = 0;
    //     Node* iter = start;
    //     Node* iter1 = head1;
    //     while (iter1!=nullptr)
    //     {
    //         if(iter==nullptr){
    //             int product = iter1->data * iter2->data + carry;
    //             int digit = product % 10;
    //             carry = product / 10;
    //             Node* temp = new Node(digit);
    //             head = temp;
    //             start = temp;
    //             iter = temp;
    //         }else if(iter->next==nullptr){
    //             int product = iter1->data * iter2->data + carry + iter->data;
    //             int digit = product % 10;
    //             carry = product / 10;
    //             Node* temp = new Node(digit);
    //             iter->next = temp;
    //             temp->prev = iter;
    //             iter = temp;
    //         } else {
    //             int product = iter1->data * iter2->data + carry + iter->data;
    //             int digit = product % 10;
    //             carry = product / 10;
    //             iter->data = digit;
    //             iter = iter -> next;
    //         }
    //         iter1 = iter1->next;
    //     }
    //     if(carry != 0){
    //         // if(iter->next==nullptr){
    //             // Node* temp = new Node(carry);
    //             // iter->next = temp;
    //             // temp->prev = iter;
    //             // iter = temp;
    //         // } 
    //         // else {
    //             int product = carry + iter->data;
    //             int digit = product % 10;
    //             carry = product / 10;
    //             iter->data = digit;
    //             iter = iter -> next;
    //         // }
    //     }      
    //     iter2 = iter2->next;
    //     start = start->next;
    // }

    // return head;
}
