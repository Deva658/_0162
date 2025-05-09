#include <iostream>
#include <string.h>
using namespace std;

class Node {
    public:
    int noMhs;
    Node*next;
};

class SingleLinkedList {
    Node *START;

    public:
    SingleLinkedList() 
    {
        START = NULL;
    }
    void addNode()
    {
        int nim;
        cout << "\nMasukan Nomor Identitas";
        cin >> nim;

        Node *nodebaru = new Node;
        nodebaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodebaru->next = START;
            START = nodebaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidaK dijalankan\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodebaru->next = current;
        previous->next = nodebaru;
    }
    bool listEmpty()
    {
        return (START == NULL);
    }
    bool Search(int nim, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;
        
        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData didalam list adalah\n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main(){

    SingleLinkedList mhs;
    int nim;
    char ch;
    while(1)
    {
        cout << endl
             << "MENU";
        cout << endl
             << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data dalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << endl
             << "Masukan piliham (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            mhs.addNode();
        }
        break;

        case '2':
        { 
            if (mhs.listEmpty())
            {
                cout << endl
                     << "List kosong" << endl;
                break;                   
            }
            cout << endl
                 << "\nMasukan no mahasiswa yang akan dihapus : ";
            cin >> nim;
            if (mhs.delNode(nim) == false)
                cout << endl
                 << "\nData tidak dimasukan" << endl;
            else 
                cout << endl
                     << "\nData dengan nomor mahasiswa " << nim << "berhasil dihapus" << endl;
        }
        break;
        case '3':
        {
            mhs.traverse();
        }
        break;
        case '4':
        {
            if (mhs.listEmpty() == true)
            {
                cout << "\nList kosong\n";
                break;
            }
            Node *previous, *current;
            cout << endl
                 << "masukan no mahasiswa yang dicari : ";
            cin >> nim;
            if (mhs.Search(nim, &previous, &current) == false)
                cout << endl
                     << "data tidak dittemukann" << endl;
            else
            {
                cout << endl
                     << "data ditemukan" << endl;
                cout << "\nNo Mahasiswa : " << current->noMhs << endl;
                cout << "\n";
            }
        }
        break;
        case '5':
        {
            exit(0);
        }  
        break;
        default;
        {
            cout << "Pilihan salah !." << endl;
        }
        break;
        }
    }
}