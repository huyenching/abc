#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Kh?i t?o danh s�ch
void initializeList(Node*& head) {
    head = nullptr;
}

// Hu? b? m?t danh s�ch
void destroyList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// �?m s? ph?n t? c?a danh s�ch
int countElements(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Th�m ph?n t? c� n?i dung x v�o d?u danh s�ch
void addToHead(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// Th�m ph?n t? c� n?i dung x v�o cu?i danh s�ch
void addToTail(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Th�m ph?n t? c� n?i dung x v�o sau ph?n t? c� d?a ch? l� P trong danh s�ch
void addAfter(Node* head, Node* p, int x) {
    if (p == nullptr) {
        std::cout << "Phan tu P khong ton tai trong danh sach" << std::endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

// X�a ph?n t? t?i v? tr� c� d?a ch? l� P trong danh s�ch
void deleteNode(Node*& head, Node* p) {
    if (head == nullptr || p == nullptr) {
        return;
    }

    if (head == p) {
        head = p->next;
        delete p;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next != p) {
        current = current->next;
    }

    if (current->next == p) {
        current->next = p->next;
        delete p;
    }
}

// Ki?m tra s? t?n t?i c?a m?t ph?n t? trong danh s�ch
bool contains(Node* head, int x) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// In danh s�ch
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* myList;

    initializeList(myList);
    addToHead(myList, 3);
    addToHead(myList, 2);
    addToHead(myList, 1);
    addToTail(myList, 4);

    std::cout << "Danh sach ban dau: ";
    printList(myList);

    std::cout << "So phan tu cua danh sach: " << countElements(myList) << std::endl;

    Node* p = myList->next; // Gi? s? ph?n t? th? hai l� P

    addAfter(myList, p, 5);
    std::cout << "Danh sach sau khi them phan tu 5 vao sau P: ";
    printList(myList);

    deleteNode(myList, p);
    std::cout << "Danh sach sau khi xoa phan tu tai P: ";
    printList(myList);

    int x = 4; // Ki?m tra s? t?n t?i c?a ph?n t? c� gi� tr? 4 trong danh s�ch
    if (contains(myList, x)) {
        std::cout << "Phan tu " << x << " ton tai trong danh sach" << std::endl;
    } else {
        std::cout << "Phan tu " << x << " khong ton tai trong danh sach" << std::endl;
    }

    destroyList(myList);

    return 0;
}

