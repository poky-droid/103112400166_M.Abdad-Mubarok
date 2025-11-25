#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};
struct list {
    node* first;
    node* last;
};

int insertLast(list& L, int dataBaru) {
    node* newNode = new node;
    newNode->data = dataBaru;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (L.first == nullptr) {
        L.first = newNode;
        L.last = newNode;
    } else {
        newNode->prev = L.last;
        L.last->next = newNode;
        L.last = newNode;
    }
    return dataBaru;
}
void deleteLast(list& L) {
    if (L.last == nullptr) {
        cout << "list kosong." << endl;
        return;
    }

    node* temp = L.last;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = L.last->prev;
        L.last->next = nullptr;
    }

    delete temp;
}
void viewList(list L) {
    node* temp = L.first;
    if (temp == nullptr) {
        cout << "list kosong." << endl;
        return;
    }

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList(list& L) {
    node* current = L.first;
    node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        L.last = L.first;
        L.first = temp->prev;
    }
}

int main(){
    int menu;
    int data;
    list L;
    L.first = nullptr;
    L.last = nullptr;

    do {
        cout << "Menu: 1 insert last, 2 delete last, 3 view, 4 reverse, 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertLast(L, data);
                break;

            case 2:
                deleteLast(L);
                break;

            case 3:
                viewList(L);
                break;

            case 4:
                reverseList(L);
                cout << "List dibalik." << endl;
                break;

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (menu != 0);

    return 0;
}



