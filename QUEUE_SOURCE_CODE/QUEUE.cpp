#include <iostream>
using namespace std;

#define max 5

class Queue {
private:
    string data[max];
    int top;

public:
    Queue() {
        top = 0;
    }

    bool isFull() {
        return (top >= max);
    }

    bool isEmpty() {
        return (top == 0);
    }

    void view() {
        if (!isEmpty()) {
            cout << "Data Antrian: " << endl;
            for (int a = top - 1; a >= 0; a--) {
                cout << a + 1 << ". " << data[a] << endl;
            }
        } else {
            cout << "Antrian Kosong" << endl;
        }

        if (isFull()) {
            cout << "Antrian Penuh!" << endl;
        }
        cout << endl;
    }

    void enqueue(string item) {
        if (!isFull()) {
            data[top] = item;
            top++;
        } else {
            cout << "Antrian sudah penuh!" << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            for (int a = 0; a < top - 1; a++) {
                data[a] = data[a + 1];
            }
            top--;
        } else {
            cout << "Antrian kosong!" << endl;
        }
    }
};

int main() {
    Queue antrian;
    int pilih;
    string isi;

    while (true) {
        system("cls");
        antrian.view();
        cout << "Menu Utama:\n1. Enqueue\n2. Dequeue\n3. Keluar\nPilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                system("cls");
                cout << "Masukkan Data Antrian: ";
                cin >> isi;
                antrian.enqueue(isi);
                break;
            case 2:
                system("cls");
                antrian.dequeue();
                break;
            case 3:
                return 0;
            default:
                cout << "ERROR: Pilihan anda tidak sesuai!" << endl;
        }
    }

    return 0;
}

