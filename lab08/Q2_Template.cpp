// #include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "__STUDENTPROGRAM__"
#include "Node.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m, x;
    cin>>t;

    while(t--)
    {
        cin >> n;
        Node *head1 = nullptr;
        Node *head2= nullptr;
        Node *newNode = nullptr;

        while (n--)
        {
            cin >> x;
            newNode = new Node(x);
            if (head1) head1->prev = newNode;
            newNode->next = head1;
            head1 = newNode;
        }

        cin>>m;
        while (m--)
        {
            cin >> x;
            newNode = new Node(x);
            if (head2) head2->prev = newNode;
            newNode->next = head2;
            head2 = newNode;
        }

        Node* head;
        head = solve(head1, head2);
        while (head->next) head = head->next;

        while (head)
        {
            cout << head->data << " ";
            head = head->prev;
        }
        cout << endl;

        while(head1){
            head1 = head1->next;
        }
        while(head2){
            head2 = head2->next;
        }
    }
    return 0;
}
