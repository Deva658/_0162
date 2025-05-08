#include <iostream>
#include <string.h>
using namespace std;

class Node {
    public:
    int noMhs;
    Node*next;
};

class list {
    Node *START;

    public:
    list() 
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

        while ((current != NULL) && (nim >== current->noMhs))
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
}
