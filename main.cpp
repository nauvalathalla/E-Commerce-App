#include <iostream>
#include "header.h"

using namespace std;

int main() {
    ListUser LU; // User
    ListBarang LB;
    ListRelasi LR;
    address_User P;
    address_Barang Q;
    address_Relasi t;
    infotypeUser u;
    infotypeBarang b;
    address_User precUser;
    address_Barang precBarang;
    int pilih;
    int IDbarang;
    int IDuser;
    int idNama;
    int cariIDUser;
    int cariIDBarang;
    address_User parent;
    address_Barang child;
    int idNamaBaru;
    int IdBarangBaru;
    address_Relasi r;
    bool isExit = false;

    createList_User(LU);
    createList_Barang(LB);
    createList_Relasi(LR);

    cout << BOLD << BLUE << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;
    cout << "|                                                                              |" << endl;
    cout << "|           W E L C O M E   T O   O U R   O N L I N E   S T O R E              |" << endl;
    cout << "|                                                                              |" << endl;
    cout << "|       FIND YOUR FAVORITE ITEMS, ENJOY GREAT DEALS & HAPPY SHOPPING ^_^       |" << endl;
    cout << "|                                                                              |" << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;
    cout << "|                        MR. SYAHRIL ARFIAN ALMAZRIL                           |" << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;
    cout << endl << endl;

    while(!isExit) {
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << "|                             M E N U   U T A M A                              |" << endl;
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << "| 1.  Tambah Data User                                                         |" << endl;
        cout << "| 2.  Tambah Data Barang                                                       |" << endl;
        cout << "| 3.  Tampilkan Daftar User                                                    |" << endl;
        cout << "| 4.  Tampilkan Daftar Barang                                                  |" << endl;
        cout << "| 5.  Hapus Data User                                                          |" << endl;
        cout << "| 6.  Hapus Data Barang                                                        |" << endl;
        cout << "| 7.  Tambah Barang Apa Yang Ingin Dibeli User?                                |" << endl;
        cout << "| 8.  Tampilkan User dan Barang telah dipesan di Toko Online                   |" << endl;
        cout << "| 9.  Hapus Data yang telah terhubung                                          |" << endl;
        cout << "| 10. Tampilkan Apakah User dan Barang memiliki hubungan                       |" << endl;
        cout << "| 11. Tampilkan Daftar User Yang Telah Memesan Barang                          |" << endl;
        cout << "| 12. Tampilkan Daftar Barang Yang Telah Dibeli User                           |" << endl;
        cout << "| 13. Tampilkan Jumlah User Dari Barang Tertentu                               |" << endl;
        cout << "| 14. Tampilkan Jumlah Barang Dari User Tertentu                               |" << endl;
        cout << "| 15. Tampilkan Jumlah Barang Yang Tidak Dibeli User                           |" << endl;
        cout << "| 16. Tampilkan Jumlah User Yang Tidak Membeli Barang                          |" << endl;
        cout << "| 17. Ganti Barang Dari User Tertentu                                          |" << endl;
        cout << "| 18. Ganti User Dari Barang Tertentu                                          |" << endl;
        cout << "| 19. Tampilkan User Yang Berhubungan Dengan Barang Tertentu                   |" << endl;
        cout << "| 20. Tampilkan Barang Yang Berhubungan Dengan User Tertentu                   |" << endl;
        cout << "| 21. Exit                                                                     |" << endl;
        cout << "+------------------------------------------------------------------------------+" << endl;

        cout << ">> Pilih Nomor Menu: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1) {   // Tambah Data User
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                             Tambah Data User                                 |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            int n;
            int y;
            cout << "Masukkan Jumlah Data User: ";
            cin >> n;
            cout << endl;

            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                 Silakan Pilih Metode Menambahkan Data ID User:               |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "| 1. Tambahkan di Awal Daftar                                                  |" << endl;
            cout << "| 2. Tambahkan Setelah ID Pengguna Tertentu                                    |" << endl;
            cout << "| 3. Tambahkan di Akhir Daftar                                                 |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;

            cout << ">> Pilih Metode Penambahan: ";
            cin  >> y;
            cout << endl;

            if(y == 1){
                for (int i = 0; i < n; i++) {
                    cout << "Masukkan ID User       : ";
                    cin >> u.ID;
                    cout << "Masukkan Nama User     : ";
                    cin >> u.Nama;
                    cout << "Masukkan Asal (Lokasi) : ";
                    cin >> u.Lokasi;
                    cout << endl;

                    P = createElmUser(u);
                    insertFirstUser(LU, P);
                    cout << ">> Data User berhasil Ditambahkan!" << endl;
                    cout << "----------------------------------------" << endl << endl;
                }

                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << "|                  *** Seluruh Data User Telah Ditambahkan ***                 |" << endl;
                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << endl << endl << endl;

            } else if(y == 2) {
                for (int i = 0; i < n; i++) {
                    cout << "Masukkan ID User       : ";
                    cin >> u.ID;
                    cout << "Masukkan Nama User     : ";
                    cin >> u.Nama;
                    cout << "Masukkan Asal (Lokasi) : ";
                    cin >> u.Lokasi;
                    cout << endl;

                    P = createElmUser(u);
                    cout << "+------------------------------------------------------------------------------+" << endl;
                    cout << "Masukkan ID User Yang Ingin Dicari dan Akan Di Tambahkan Setelahnya: ";
                    cin >> cariIDUser;
                    precUser = findUser(LU, cariIDUser);
                    if (precUser != NULL) {
                        insertAfterUser(LU, precUser, P);
                        cout << endl;
                        cout << ">> Mencari Data User ..." << endl;
                        cout << ">> Data User berhasil ditambahkan!" << endl;
                        cout << "----------------------------------------" << endl << endl;
                        cout << "+------------------------------------------------------------------------------+" << endl;
                        cout << "|                  *** Seluruh Data User Telah Ditambahkan ***                 |" << endl;
                        cout << "+------------------------------------------------------------------------------+" << endl;
                        cout << endl << endl << endl;
                    } else {
                        cout << endl;
                        cout << ">> Mencari Data User ID ..." << endl;
                        cout << ">> Data User dengan ID Tersebut Tidak Ditemukan, Data Baru Tidak Ditambahkan." << endl << endl;
                        cout << "+------------------------------------------------------------------------------+" << endl;
                        cout << endl << endl << endl;
                    }
                }

            } else if(y == 3) {
                for (int i = 0; i < n; i++) {
                    cout << "Masukkan ID User       : ";
                    cin >> u.ID;
                    cout << "Masukkan Nama User     : ";
                    cin >> u.Nama;
                    cout << "Masukkan Asal (Lokasi) : ";
                    cin >> u.Lokasi;
                    cout << endl;

                    P = createElmUser(u);
                    insertLastUser(LU, P);
                    cout << ">> Data User berhasil ditambahkan!" << endl;
                    cout << "----------------------------------------" << endl << endl;
                }

                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << "|                  *** Seluruh Data User Telah Ditambahkan ***                 |" << endl;
                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << endl << endl << endl;

            } else {
                cout << ">> Metode Penambahan Tidak Valid." << endl << endl;
            }

        } else if (pilih == 2) {  // Tambah Data Barang
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                             Tambah Data Barang                               |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            int n;
            int y;
            cout << "Masukkan Jumlah Data Barang: ";
            cin >> n;
            cout << endl;

            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|               Silakan Pilih Metode Menambahkan Data Barang                   |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "| 1. Tambahkan di Awal Daftar                                                  |" << endl;
            cout << "| 2. Tambahkan Setelah ID Barang Tertentu                                      |" << endl;
            cout << "| 3. Tambahkan di Akhir Daftar                                                 |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;

            cout << ">> Pilih Metode Penambahan: ";
            cin  >> y;
            cout << endl;

            if(y == 1) {
                for (int i = 0; i < n; i++) {
                    cout << "Masukkan ID Barang    : ";
                    cin >> b.ID;
                    cout << "Masukkan Jenis Barang : ";
                    cin >> b.jenisBarang;
                    cout << "Masukkan Nama Barang  : ";
                    cin >> b.NamaBarang;
                    cout << endl;

                    Q = createElmBarang(b);
                    insertFirstBarang(LB, Q);
                    cout << ">> Data Barang berhasil ditambahkan!" << endl;
                    cout << "----------------------------------------" << endl << endl;
                }

                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << "|                   *** Seluruh Data Barang Telah Ditambahkan ***              |" << endl;
                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << endl << endl << endl;

            } else if(y == 2) {
                for (int i = 0; i < n; i++) {
                    cout << "Masukkan ID Barang    : ";
                    cin >> b.ID;
                    cout << "Masukkan Jenis Barang : ";
                    cin >> b.jenisBarang;
                    cout << "Masukkan Nama Barang  : ";
                    cin >> b.NamaBarang;
                    cout << endl;

                    Q = createElmBarang(b);
                    cout << "+------------------------------------------------------------------------------+" << endl;
                    cout << "Masukkan ID Barang Yang Ingin Dicari Dan Akan Di Tambahkan Setelahnya: ";
                    cin >> cariIDBarang;
                    precBarang = findBarang(LB, cariIDBarang);
                    if (precBarang != NULL) {
                        insertAfterBarang(LB, precBarang, Q);
                        cout << endl;
                        cout << ">> Mencari Data Barang ..." << endl;
                        cout << ">> Data Barang berhasil ditambahkan!" << endl;
                        cout << "----------------------------------------" << endl << endl;
                        cout << "+------------------------------------------------------------------------------+" << endl;
                        cout << "|                  *** Seluruh Data Barang Telah Ditambahkan ***              |" << endl;
                        cout << "+------------------------------------------------------------------------------+" << endl;
                        cout << endl << endl << endl;
                    } else {
                        cout << endl;
                        cout << ">> Mencari Data Barang ..." << endl;
                        cout << ">> Data Barang dengan ID tersebut Tidak Ditemukan, Data baru tidak ditambahkan." << endl << endl;
                        cout << "+------------------------------------------------------------------------------+" << endl;
                        cout << endl << endl << endl;
                    }
                }

            } else if(y == 3) {
                for (int i = 0; i < n; i++) {
                    cout << "Masukkan ID Barang    : ";
                    cin >> b.ID;
                    cout << "Masukkan Jenis Barang : ";
                    cin >> b.jenisBarang;
                    cout << "Masukkan Nama Barang  : ";
                    cin >> b.NamaBarang;
                    cout << endl;

                    Q = createElmBarang(b);
                    insertLastBarang(LB, Q);
                    cout << ">> Data Barang berhasil ditambahkan!" << endl;
                    cout << "----------------------------------------" << endl << endl;
                }

                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << "|                   *** Seluruh Data Barang Telah Ditambahkan ***              |" << endl;
                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << endl << endl << endl;

            } else {
                cout << ">> Metode Penambahan Tidak Valid." << endl << endl;
            }

        } else if (pilih == 3) {  // Tampilkan Daftar User
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                                Daftar User                                   |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showParent(LU);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 4) {  // Tampilkan Daftar Barang
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                                Daftar Barang                                 |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showChild(LB);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 5) {  // Hapus Data User
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                             Hapus Data User                                  |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "| Berikut Daftar User Yang Terdaftar:                                          |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showParent(LU);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID User Yang Ingin Anda Hapus: ";
            cin >> IDuser;
            cout << endl;

            P = findUser(LU, IDuser);
            if (P != NULL) {
                DeleteThatParent(LU, P);
                cout << ">> Mencari Data User ID ..." << endl;
                cout << ">> Data User Dengan ID " << IDuser << " Berhasil Dihapus." << endl;
            } else {
                cout << ">> Mencari Data User ID ..." << endl;
                cout << ">> Data User ID Tidak Ditemukan." << endl;
            }

            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 6) {  // Hapus Data Barang
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                             Hapus Data Barang                                |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "| Berikut daftar Barang yang tersedia:                                         |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showChild(LB);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID Barang Yang Ingin Anda Hapus: ";
            cin >> IDbarang;
            cout << endl;

            Q = findBarang(LB, IDbarang);
            if (Q != NULL) {
                deleteThatChild(LB, Q);
                cout << ">> Mencari Data ID Barang ..." << endl;
                cout << ">> Data Barang Dengan ID " << IDbarang << " Berhasil Dihapus." << endl;
            } else {
                cout << ">> Mencari Data ID Barang ..." << endl;
                cout << ">> Data ID Barang Tidak Ditemukan." << endl;
            }

            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 7) {  // Barang Apa Yang Ingin Dibeli User
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                     Daftar User Dan Barang Yang Tersedia                     |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "| Pilih User dan Barang Untuk Membuat Pesanan:                                 |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showParent(LU);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showChild(LB);
            cout << "+------------------------------------------------------------------------------+" << endl;

            t = createElmRelasi();

            cout << "Masukkan ID User yang akan membeli Barang: ";
            cin >> IDuser;
            cout << "Masukkan ID Barang yang ingin dibeli User: ";
            cin >> IDbarang;
            cout << endl;

            parent = findUser(LU, IDuser);
            child  = findBarang(LB, IDbarang);
            if (parent != NULL && child != NULL) {
                connect(LR, parent, child, t);
                cout << ">> User ID " << IDuser << " Melakukan Pembelian Pada ID Barang " << IDbarang << endl;
                cout << ">> [Pesanan Berhasil Ditambahkan] " << endl;
            } else {
                cout << ">> Data Tidak Ditemukan!" << endl;
                cout << ">> Pastikan Data User Dan Barang Tersedia." << endl;
            }

            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 8) {  // Tampilkan Barang Yang Dibeli Oleh User
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                  Daftar User Dan Barang Yang Telah Dibeli                    |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            showInfoRelation(LU, LB, LR);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        }else if(pilih == 9){
                showInfoRelation(LU,LB,LR);
                cout << "--------------------------------------------------------------------------------" << endl;
                cout << endl;
                cout << ">> Masukkan ID User yang  berada dalam List relasi yang ingin dihapus     : " ;
                cin  >> IDuser;
                cout << ">> Masukkan ID Barang yang  berada dalam List relasi yang ingin dihapus   : " ;
                cin  >> IDbarang;
                cout << endl;

                        if (IDuser!= 0 && IDbarang != 0) {
                          address_Relasi R = findRelasi( LR, IDuser, IDbarang);
                                deleteThatConnection(LR,R);
                                cout << "Mencari Relasi................" << endl;
                                cout << "=============================="<<endl;
                                cout << "Data Relasi Berhasil Dihapus"<<endl;
                                cout << "=============================="<<endl;
                                cout << endl << endl << endl;

                    }

        } else if (pilih == 10) {
            int IDU;
            int IDB;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                  Daftar User Dan Barang Yang Tersedia                        |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showParent(LU);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showChild(LB);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << ">> Masukkan ID User      : ";
            cin >> IDU;
            cout << ">> Masukkan ID Barang    : ";
            cin >> IDB;
            cout << endl;

            r = findRelasi( LR, IDU, IDB);
            if (r != NULL) {
                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << "|                     User dan Barang Memiliki Hubungan                        |" << endl;
                cout << "+------------------------------------------------------------------------------+" << endl;
            } else {
                cout << "+------------------------------------------------------------------------------+" << endl;
                cout << "|                   User dan Barang Tidak Memiliki Hubungan                    |" << endl;
                cout << "+------------------------------------------------------------------------------+" << endl;
            }

            cout << endl << endl << endl;

        }else if(pilih == 11){
            cout << ">> Mencari Data User Dan Data Barang..." << endl;
            cout << ">> Menampilkan Daftar User Yang Telah Memesan Barang" << endl;
            showInfoRelationParent( LU,  LR);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        }else if(pilih == 12){
            cout << ">> Mencari Data User Dan Data Barang..." << endl;
            cout << ">> Mampilkan Daftar Barang Yang telah dibeli user" << endl;
            showInfoRelationChild( LB, LR);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 13) {
            int CariIDUser;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showParent(LU);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID User Yang Ingin Menampilkan Jumlah Barang: ";
            cin >> CariIDUser;
            cout << endl;
            int jml = countJumlahChildFromSpecificParent(LR, CariIDUser);
            cout << ">> Mencari Data ID User..." << endl;
            cout << ">> Mencari Data ID Barang..." << endl;
            cout << ">> Jumlah Barang Dari User Dengan ID User " << CariIDUser << " = " << jml << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 14) {
            int cariIDBarang;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            showChild(LB);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID Barang Yang Ingin Menampilkan Jumlah User: ";
            cin >> cariIDBarang;
            cout << endl;
            int jml = countJumlahParentFromSpecificChild(LR, cariIDBarang);
            cout << ">> Mencari Data ID User..." << endl;
            cout << ">> Mencari Data ID Barang..." << endl;
            cout << ">> Jumlah User Dari Barang Dengan ID Barang " << cariIDBarang << " = " << jml << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 15) {
            int x = countJumlahChildNoParent(LB, LR);
            cout << "+------------------------------------------------------------------------------+" << endl << endl;
            cout << ">> Mencari Barang Yang Tidak Dibeli User..." << endl;
            cout << ">> Jumlah Barang Yang Tidak Dibeli User = " << x << endl;
            cout << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 16) {
            int x = countJumlahParentNoChild(LU, LR);
            cout << "+------------------------------------------------------------------------------+" << endl << endl;
            cout << ">> Mencari User Yang Tidak Membeli Barang... " << endl;
            cout << ">> Jumlah User Yang Tidak Membeli Barang = " << x << endl;
            cout << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 17) {
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                      Mengganti Barang dari User Tertentu                     |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            showInfoRelation(LU, LB, LR);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID User           : ";
            cin >> IDuser;
            cout << "Masukkan ID Barang lama    : ";
            cin >> idNama;
            cout << "Masukkan ID Barang terbaru : ";
            cin >> idNamaBaru;
            cout << endl;

            bool perubahanBerhasil;
            changeChildFromSpecificParent(LB, LR, IDuser, idNama, idNamaBaru, perubahanBerhasil);

            if (perubahanBerhasil) {
                cout << ">> Mencari Data ID User..." << endl;
                cout << ">> Mencari Data ID Barang Lama..." << endl;
                cout << ">> Mencari Data ID Barang Baru..." << endl;
                cout << ">> Data Barang Berhasil Diganti." << endl;
            } else {
                cout << ">> Data Tidak Ditemukan!" << endl;
                cout << ">> Data Barang Tidak Dapat Diganti!" << endl;
            }

            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;

        } else if (pilih == 18) {
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                      Mengganti User dari Barang Tertentu                     |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            showInfoRelation(LU, LB, LR);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID Barang       : ";
            cin >> idNama;
            cout << "Masukkan ID User lama    : ";
            cin >> IDuser;
            cout << "Masukkan ID User terbaru : ";
            cin >> IdBarangBaru;
            cout << endl;

            bool perubahanBerhasil;
            changeParentFromSpecificChild(LU, LR, IDuser, idNama, IdBarangBaru, perubahanBerhasil);

            if (perubahanBerhasil) {
                cout << ">> Mencari Data ID Barang..." << endl;
                cout << ">> Mencari Data ID User Lama..." << endl;
                cout << ">> Mencari Data ID User Baru..." << endl;
                cout << ">> Data User Berhasil Diganti." << endl;
            } else {
                cout << ">> Data Tidak Ditemukan!" << endl;
                cout << ">> Data User Tidak Dapat Diganti!" << endl;
        }
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << endl << endl << endl;

        } else if (pilih == 19) {
            int idBarang;
            cout << "+------------------------------------------------------------------------------+" << endl << endl;
            showChild(LB);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID Barang: ";
            cin >> idBarang;

            cout << endl;
            showinfoUserDariBarangTertentu(LR, idBarang);
            cout << endl << endl << endl;

        } else if (pilih == 20) {
            int idUser;
            cout << "+------------------------------------------------------------------------------+" << endl << endl;
            showParent(LU);
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "Masukkan ID User: ";
            cin  >> idUser;

            cout << endl;
            showinfoBarangDariUserTertentu(LR, idUser);
            cout << endl << endl << endl;

        } else if (pilih == 21) {
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|******************************************************************************|" << endl;
            cout << "|*                       THANK YOU FOR VISITING                               *|" << endl;
            cout << "|*               HOPE YOU HAVE A WONDERFUL SHOPPING DAY :)                    *|" << endl;
            cout << "|*                                                                            *|" << endl;
            cout << "|*                                                                            *|" << endl;
            cout << "|*                       MR. SYAHRIL ARFIAN ALMAZRIL                          *|" << endl;
            cout << "|******************************************************************************|" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;
            isExit = true;

        } else {
            cout << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << "|                            Pilihan Tidak Valid                               |" << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl << endl << endl;
        }
    }

    return 0;
}
