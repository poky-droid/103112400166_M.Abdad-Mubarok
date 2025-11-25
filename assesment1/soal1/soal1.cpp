#include <iostream>
using namespace std;

struct Node
{
    string nama;
    Node* next;
};

struct list
{
   Node* first;

};

string insertName(list &L, string namaBaru)
{
    Node* newNode = new Node;
    newNode->nama = namaBaru;
    newNode->next = nullptr;

    if (L.first == nullptr)
    {
        L.first = newNode;
    }
    else
    {
        Node* temp = L.first;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return namaBaru;
}
void DeleteName(list &L, string namaHapus)
{
    if (L.first == nullptr)
    {
        cout << "list kosong." << endl;
        return;
    }

    Node* temp = L.first;
    Node* prev = nullptr;

    while (temp != nullptr && temp->nama != namaHapus)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "nama tidak ditemukan " << endl;
        return;
    }

    if (prev == nullptr)
    {
        L.first = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
}
void viewList(list L)
{
    Node* temp = L.first;
    if (temp == nullptr)
    {
        cout << "list kosong." << endl;
        return;
    }

    while (temp != nullptr)
    {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hitungGenapHurufNama(list L)
{
    Node* temp = L.first;
    int count = 0;

    while (temp != nullptr)
    {
        if (temp->nama.length() % 2 == 0)
        {
            count++;
        }
        temp = temp->next;
    }

    cout << "jumlah nama dengan huruf genap: " << count << endl;
}
int main(){
    int menu;
    string nama;
    list L;
    L.first = nullptr;
do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                insertName(L, nama);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> nama;
                DeleteName(L, nama);
                break;

            case 3:
                viewList(L);
                break;

            case 4:
                hitungGenapHurufNama(L);
                break;

            case 0:
                break;

            default:
                cout << "Menu tidak valid\n";
        }

    } while (menu != 0);

    return 0;


}
