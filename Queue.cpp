//Import Library
#include <iostream>
#include <stdlib.h>
#include <conio.h>

//Deklarasi Maximal atau Batas
#define MAX 8

using namespace std;

//Deklarasi variable Queue
struct Queue{
    int data[MAX];
    int depan;
    int belakang;
}; 
Queue q;

//Fungsi Inisialisasi
void create()
{
    //Inisialisasi variable depan dan belakang set -1
    q.depan = q.belakang = -1;
}

//Fungsi Kosong
int isEmpty()
{
   return (q.depan == -1 && q.belakang == -1) ? true : false;
}

//Fungsi Hapus Seluruh Data
void clear()
{
    q.depan = q.belakang = -1;
}

//Fungsi Insert Data (Enqueue)
void enqueue(int data)
{
         //Kondisi Jika Nilai Depan = -1
        if(q.depan == -1){
            q.depan = 0;
            q.belakang = (q.belakang + 1) % MAX;
            //Input data kedalama variable array dari parameter
            q.data[q.belakang] = data;

            cout << "Data " << q.data[q.belakang] << " ditambahkan kedalam Queue\n";

        //Kondisi Jika Nilai Variable Belakang > -1 & Nilai Variable Belakang < MAX-1
        }else if(q.belakang > -1 && q.belakang < MAX-1){
            q.belakang++;
            q.data[q.belakang] = data;
            cout << "Data " << q.data[q.belakang] << " ditambahkan kedalam Queue\n"; 

        //Kondisi Jika Nilai Variable Belakang Sama Dengan MAX-1 & Nilai Variable Depan > 0
        }else if(q.belakang == MAX-1 && q.depan > 0){
            q.belakang = 0;
            q.data[q.belakang] = data;
            cout << "Data " << q.data[q.belakang] << " ditambahkan kedalam Queue\n";    

        //Kondisi Jika Nilai Variable Belakang >= 0 & Nilai Variable depan <= MAX -1
        }else if(q.belakang >= 0 && q.depan <= MAX-1){
            q.belakang++;
            q.data[q.belakang] = data;
            cout << "Data " << q.data[q.belakang] << " ditambahkan kedalam Queue\n";    
        }
} //

//Fungsi Delete Data (Dequeue)
void dequeue()
{
    //Cek Data Queue Kosong
    if(isEmpty()){
        cout<<"Queue Kosong...\n";
    }else{
        if(q.depan == q.belakang){
            q.depan = q.belakang = -1;
           
            cout << "Data Dikeluarkan\n";
        }
        else{
            q.depan = (q.depan + 1) % MAX;
           
            cout << "Data Dikeluarkan\n";

        }
    }
}

//Fungsi Display
void display()
{
    //Cek Queue Kosong
    if(isEmpty()){
        cout<<"Queue Kosong...\n";
    }else{
            cout << "====================================" << endl;
            cout << "   Daftar Queue    " << endl;
            cout << "====================================" << endl;
        if(q.depan <= q.belakang){
            //Tampil Data Jika q.depan lebih kecil atau sama dengan q.belakang
            for(int i = q.depan; i <= q.belakang; i++){
                cout << "=======  " << q.data[i] << "   =======" << endl;
            }
        }else{
            //Tampil Data Depan
            for (int i = q.depan; i < MAX; i++)
            {
                cout << "=======  " << q.data[i] << "   =======" << endl;
            }
            
            //Tampil Data Belakang
            for (int i = 0; i <= q.belakang; i++)
            {
                cout << "=======  " << q.data[i] << "   =======" << endl;
            }
        }
            cout << "====================================" << endl;
    }
} //

int main ()
{
    system("cls");
    //Deklarasi variable
    int pilihan;
    int data;

    //Jalankan fungsi create
    create();

    //Tampil menu
    do{
        cout << "====================================" << endl;
        cout << "   ANTRIAN CIRCULAR QUEUE   " << endl;
        cout << "====================================" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Hapus Semua" << endl;
        cout << "4. Cetak" << endl;
        cout << "5. Keluar" << endl;
        cout << "====================================" << endl;
        cout << "Masukan Pilihan Anda: "; cin >> pilihan;

        //Pemilihan menu
        switch (pilihan)
        {

        //Enqueue atau memasukan data
        case 1:
            system("cls");
            if((q.belakang + 1) % MAX == q.depan)
            {
                cout << "Queue Penuh...\n";

            }else{
                cout << "Masukan Angka: "; cin >> data;
             //Menjalankan dan mengirimkan data ke parameter fungsi enqueue
                enqueue(data);
            } 
            cout << endl;
            system("pause");
            system("cls");
            break;

        //Dequeue atau mengeluarkan data
        case 2:
            //Menjalankan fungsi dequeue
            system("cls");
            dequeue();
            cout << endl;
            system("pause");
            system("cls");
            break;

        //Clear atau hapus semua data
        case 3:
            //Menjalankan fungsi clear
            system("cls");
            clear();
            cout << "Data Queue dikosongkan...\n";
            cout << endl;
            system("pause");
            system("cls");
            break;

        //Display atau tampil data
        case 4:
            //Menjalankan fungsi display
            system("cls");
            cout << "Nilai Variable Depan: " << q.depan << endl;
            cout << "Nilai Variable Data (Array) Depan " << q.data[q.depan] << endl;
            cout << "Nilai Variable Belakang: " << q.belakang << endl;
            cout << "Nilai Variable Data (Array) Belakang " << q.data[q.belakang] << endl << endl;
            display();
            cout << endl;
            system("pause");
            system("cls");
            break;

        default:
        system("cls");
            cout << "Terima Kasih";
            system("exit");
            break;
        }
    }while(pilihan != 5);
}
