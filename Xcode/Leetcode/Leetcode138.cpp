//
//  Leetcode138.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/31.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    Node* copyRandomList(Node* head) {
        if (!head) return head;

        Node *res = new Node(head->val, nullptr, nullptr);
        res->random = head->random;
        Node *root = res;

        unordered_map<Node*, Node*> map;
        map[head] = res;
        while (head->next != nullptr) {
            Node *tmp = new Node(head->next->val, nullptr, nullptr);
            map[head->next] = tmp;
            tmp->random = head->next->random;
            res->next = tmp;
            res->random = head->random;
            res = res->next;
            head = head->next;
        }

        Node *tmp = root;
        while (tmp != nullptr) {
            tmp->random = map[tmp->random];
            tmp = tmp->next;
        }

        return root;
    }

    void Leetcode::main_138() {
        Node *node1 = new Node(1);
        Node *node2 = new Node(2);
        Node *node3 = new Node(3);
        Node *node4 = new Node(4);

        node1->next = node2;
        node2->next = node3;
        node1->random = node3;
        node2->random = node3;
        node3->random = node1;
        node4->random = node4;

        Node *copy = copyRandomList(node4);
        cout << "a" << endl;
    }
}
