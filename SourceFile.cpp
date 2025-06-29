#include "Header.h"

void createList_User(ListUser &LU) {
    first(LU) = Nil;
}

void createList_Barang(ListBarang &LB) {
    first(LB) = Nil;
    last(LB) = Nil;
}

void createList_Relasi(ListRelasi &LR) {
    first(LR) = NULL;
}

address_User createElmUser(infotypeUser InfoUser) {
    address_User P = new ElmUser;
    info(P) = InfoUser;
    next(P) = Nil;
    return P;
}

address_Barang createElmBarang(infotypeBarang InfoBarang) {
    address_Barang P = new ElmBarang;
    info(P) = InfoBarang;
    next(P) = Nil;
    prev(P) = Nil;
    return P;
}

address_Relasi createElmRelasi() {
    address_Relasi P = new ElmRelasi;
    pUp(P) = Nil;
    pDown(P) = Nil;
    next(P) = Nil;
    return P;
}

void insertFirstUser(ListUser &LU, address_User P) {
    if (first(LU) != Nil) {
        next(P) = first(LU);
        first(LU) = P;
    } else {
        first(LU) = P;
    }
}

void insertLastUser(ListUser &LU, address_User p) {
    address_User q = first(LU);
    if (first(LU) == NULL) {
        first(LU) = p;
    } else {
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = p;
    }
}

void insertAfterUser(ListUser &LU, address_User prec, address_User p) {
    if (next(prec) == NULL) {
        next(prec) = p;
    } else {
        next(p) = next(prec);
        next(prec) = p;
    }
}

void insertFirstBarang(ListBarang &LB, address_Barang P) {
    if (first(LB) != Nil) {
        next(P) = first(LB);
        prev(first(LB)) = P;
        first(LB) = P;
    } else {
        first(LB) = P;
        last(LB) = P;
    }
}

void insertAfterBarang(ListBarang &LB, address_Barang prec, address_Barang p) {
    if (first(LB) == NULL) {
        first(LB) = p;
        last(LB) = p;
        next(p) = NULL;
        prev(p) = NULL;
    } else if (next(prec) == NULL) {
        insertLastBarang(LB, p);
    } else {
        next(p) = next(prec);
        prev(p) = prec;
        prev(next(prec)) = p;
        next(prec) = p;
    }
}

void insertLastBarang(ListBarang &LB, address_Barang p) {
    if (first(LB) == NULL) {
        first(LB) = p;
        last(LB) = p;
        next(p) = NULL;
        prev(p) = NULL;
    } else {
        prev(p) = last(LB);
        next(last(LB)) = p;
        last(LB) = p;
    }
}

void insertFirstConnection(ListRelasi &LR, address_Relasi p) {
    if (first(LR) == NULL) {
        first(LR) = p;
    } else {
        next(p) = first(LR);
        first(LR) = p;
    }
}

void insertAfterConnection(ListRelasi &LR, address_Relasi prec, address_Relasi P) {
    if (next(prec) == NULL) {
        next(prec) = P;
    } else {
        next(P) = next(prec);
        next(prec) = P;
    }
}

void insertLastConnection(ListRelasi &LR, address_Relasi p) {
    address_Relasi q = first(LR);
    if (first(LR) == NULL) {
        first(LR) = p;
    } else {
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = p;
    }
}

void deleteFirstParent(ListUser &LU, address_User P) {
    if (first(LU) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(first(LU)) == NULL) {
        P = first(LU);
        first(LU) = NULL;
    } else {
        P = first(LU);
        first(LU) = next(first(LU));
        next(P) = NULL;
    }
}

void deleteAfterParent(ListUser &LU, address_User q, address_User P) {
    if (first(LU) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(q) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(next(q)) == NULL) {
        P = next(q);
        next(q) = NULL;
    } else {
        P = next(q);
        next(q) = next(P);
        next(P) = NULL;
    }
}

void deleteLastParent(ListUser &LU, address_User p) {
    address_User q = first(LU);
    if (first(LU) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(first(LU)) == NULL) {
        p = first(LU);
        first(LU) = NULL;
    } else {
        while (next(next(q)) != NULL) {
            q = next(q);
        }
        p = next(q);
        next(q) = NULL;
    }
}

void DeleteThatParent(ListUser &LU, address_User p) {
    address_User q;
    if (first(LU) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (p == first(LU)) {
        deleteFirstParent(LU, p);
    } else if (next(p) == NULL) {
        deleteLastParent(LU, p);
    } else {
        q = first(LU);
        while (next(q) != p) {
            q = next(q);
        }
        next(q) = next(p);
        p = NULL;
    }
}

void deleteFirstChild(ListBarang &LB, address_Barang p) {
    if (first(LB) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (LB.first == LB.last) {
        p = first(LB);
        first(LB) = NULL;
        last(LB) = NULL;
    } else {
        p = first(LB);
        first(LB) = next(first(LB));
        prev(first(LB)) = NULL;
        next(p) = NULL;
    }
}

void deleteLastChild(ListBarang &LB, address_Barang p) {
    if (first(LB) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (first(LB) == last(LB)) {
        p = first(LB);
        first(LB) = NULL;
        last(LB) = NULL;
    } else {
        p = last(LB);
        last(LB) = prev(last(LB));
        next(last(LB)) = NULL;
        prev(p) = NULL;
    }
}

void deleteThatChild(ListBarang &LB, address_Barang p) {
    address_Barang q;
    if (p == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (first(LB) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (p == first(LB)) {
        deleteFirstChild(LB, p);
    } else if (p == last(LB)) {
        deleteLastChild(LB, p);
    } else {
        q = first(LB);
        while (next(q) != p) {
            q = next(q);
        }
        next(q) = next(p);
        p = NULL;
    }
}

void deleteFirstConnection(ListRelasi &LR, address_Relasi p) {
    if (first(LR) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(first(LR)) == NULL) {
        p = first(LR);
        first(LR) = NULL;
    } else {
        p = first(LR);
        first(LR) = next(first(LR));
        next(p) = NULL;
    }
}

void deleteAfterConnection(ListRelasi &LR, address_Relasi prec, address_Relasi p) {
    if (first(LR) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(prec) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(next(prec)) == NULL) {
        p = next(prec);
        next(prec) = NULL;
    } else {
        p = next(prec);
        next(prec) = next(p);
        next(p) = NULL;
    }
}

void deleteLastConnection(ListRelasi &LR, address_Relasi p) {
    address_Relasi q = first(LR);
    if (first(LR) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (next(first(LR)) == NULL) {
        p = first(LR);
        first(LR) = NULL;
    } else {
        while (next(next(q)) != NULL) {
            q = next(q);
        }
        p = next(q);
        next(q) = NULL;
    }
}

void deleteThatConnection(ListRelasi &LR, address_Relasi prec) {
    address_Relasi q;
    if (first(LR) == NULL) {
        cout << "Data Tidak Ditemukan!" << endl;
    } else if (prec == first(LR)) {
        deleteFirstConnection(LR, prec);
    } else if (next(prec) == NULL) {
        deleteLastConnection(LR, prec);
    } else {
        q = first(LR);
        while (next(q) != prec) {
            q = next(q);
        }
        next(q) = next(prec);
        prec = NULL;
    }
}

void deleteBarangYangDiList(ListBarang &LB, address_Barang &P) {
    address_Barang q;
    if (first(LB) == Nil && last(LB) == Nil && P == Nil) {
        return;
    }
    if (P == first(LB) && P == last(LB)) {
        first(LB) = Nil;
        last(LB) = Nil;
    } else if (P == first(LB)) {
        first(LB) = next(P);
        prev(first(LB)) = Nil;
        next(P) = Nil;
    } else if (P == last(LB)) {
        q = prev(P);
        last(LB) = q;
        next(q) = Nil;
        prev(P) = Nil;
    } else {
        q = prev(P);
        next(q) = next(P);
        prev(next(P)) = q;
        next(P) = Nil;
        prev(P) = Nil;
    }
}

address_User findUser(ListUser LU, int ID) {
    address_User p = first(LU);
    while (p != NULL) {
        if (info(p).ID == ID) {
            return p;
        } else {
            p = next(p);
        }
    }
    return NULL;
}

address_Relasi findRelasi( ListRelasi LR, int IDUser, int IDBarang) {
    address_Relasi r = first(LR);
    while (r != NULL) {
        if (info(pUp(r)).ID == IDUser && info(pDown(r)).ID == IDBarang) {
            return r;
        } else {
            r = next(r);
        }
    }
    return NULL;
}

address_Barang findBarang(ListBarang LB, int ID) {
    address_Barang p = first(LB);
    while (p != NULL) {
        if (info(p).ID == ID) {
            return p;
        } else {
            p = next(p);
        }
    }
    return NULL;
}

void showParent(ListUser LU) {
    address_User P = first(LU);
    int i = 1;
    while (P != NULL) {
        cout << "ID USER        : " << info(P).ID << endl;
        cout << "Nama User      : " << info(P).Nama << endl;
        cout << "Asal User      : " << info(P).Lokasi << endl;
        cout << endl;
        i++;
        P = next(P);
    }
}

void connect(ListRelasi &LR, address_User parent, address_Barang child, address_Relasi p) {
    if (first(LR) == NULL) {
        insertFirstConnection(LR, p);
    } else {
        insertLastConnection(LR, p);
    }
    pUp(p) = parent;
    pDown(p) = child;
}

void showChild(ListBarang LB) {
    address_Barang P = first(LB);
    int i = 1;
    while (P != NULL) {
        cout << "ID BARANG      : " << info(P).ID << endl;
        cout << "Nama Barang    : " << info(P).NamaBarang << endl;
        cout << "Jenis Barang   : " << info(P).jenisBarang << endl;
        cout << endl;
        i++;
        P = next(P);
    }
}

void showInfoRelation(ListUser LU, ListBarang LB, ListRelasi LR) {
    address_Relasi p = first(LR);
    int i = 1;
    while (p != NULL) {
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Info User yang membeli Barang di Toko Online" << endl;
        cout << endl;
        cout << "ID          : " << info(pUp(p)).ID << endl;
        cout << "Nama        : " << info(pUp(p)).Nama << endl;
        cout << "Asal        : " << info(pUp(p)).Lokasi << endl;
        cout << endl;
        cout << "Info Barang Yang Dibeli Oleh User " << endl;
        cout << endl;
        cout << "ID          : " << info(pDown(p)).ID << endl;
        cout << "Nama        : " << info(pDown(p)).NamaBarang << endl;
        cout << "Jenis Barang: " << info(pDown(p)).jenisBarang << endl;
        p = next(p);
    }
}

void showInfoRelationParent(ListUser LU, ListRelasi LR){
    address_Relasi p = first(LR);
    while(p!= NULL){
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Info User yang membeli Barang di Toko Online" << endl;
        cout << endl;
        cout << "ID          : " << info(pUp(p)).ID << endl;
        cout << "Nama        : " << info(pUp(p)).Nama << endl;
        cout << "Asal        : " << info(pUp(p)).Lokasi << endl;
        cout << endl;
        p = next(p);
    }
}

void showInfoRelationChild(ListBarang LB, ListRelasi LR){
    address_Relasi p = first(LR);
    while(p!= NULL){
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Info Barang Yang Dibeli Oleh User " << endl;
        cout << endl;
        cout << "ID          : " << info(pDown(p)).ID << endl;
        cout << "Nama        : " << info(pDown(p)).NamaBarang << endl;
        cout << "Jenis Barang: " << info(pDown(p)).jenisBarang << endl;
        cout << endl;
        p = next(p);
    }
}

int countJumlahChildFromSpecificParent(ListRelasi LR, int ID) {
    address_Relasi p = first(LR);
    int count = 0;
    while (p != NULL) {
        if (info(pUp(p)).ID == ID) {
            count++;
        }
        p = next(p);
    }
    return count;
}

int countJumlahParentFromSpecificChild(ListRelasi LR, int ID) {
    address_Relasi p = first(LR);
    int count = 0;
    while (p != NULL) {
        if (info(pDown(p)).ID == ID) {
            count++;
        }
        p = next(p);
    }
    return count;
}

int countJumlahChildNoParent(ListBarang LB, ListRelasi LR) {
    address_Barang p = first(LB);
    address_Relasi q;
    int x = 0;
    bool hasParent = false;
    while (p != NULL) {
        q = first(LR);
        hasParent = false;
        while (q != NULL) {
            if (pDown(q) == p) {
                hasParent = true;
                q = next(q);
            } else {
                q = next(q);
            }
        }
        if (!hasParent) {
            x = x + 1;
        }
        p = next(p);
    }
    return x;
}

int countJumlahParentNoChild(ListUser LU, ListRelasi LR) {
    address_User p = first(LU);
    address_Relasi q;
    int count2 = 0;
    bool hasChild = false;
    while (p != NULL) {
        q = first(LR);
        hasChild = false;
        while (q != NULL) {
            if (pUp(q) == p) {
                hasChild = true;
                q = next(q);
            } else {
                q = next(q);
            }
        }
        if (!hasChild) {
            count2++;
        }
        p = next(p);
    }
    return count2;
}

void changeChildFromSpecificParent(ListBarang &LB, ListRelasi &LR, int cariUserId, int cariBarangId, int idBarangBaru, bool &berhasil) {
    address_Relasi p = first(LR);
    berhasil = false;
    while (p != NULL && !berhasil) {
        if (info(pUp(p)).ID == cariUserId && info(pDown(p)).ID == cariBarangId) {
            address_Barang q = first(LB);
            while (q != NULL && !berhasil) {
                if (info(q).ID == idBarangBaru) {
                    pDown(p) = q;
                    berhasil = true;
                }
                q = next(q);
            }
        }
        p = next(p);
    }
}

void changeParentFromSpecificChild(ListUser &LU, ListRelasi &LR, int cariUserId, int cariBarangId, int IdUserBaru, bool &berhasil) {
    address_Relasi p = first(LR);
    berhasil = false;
    while (p != NULL && !berhasil) {
        if (info(pUp(p)).ID == cariUserId && info(pDown(p)).ID == cariBarangId) {
            address_User q = first(LU);
            while (q != NULL && !berhasil) {
                if (info(q).ID == IdUserBaru) {
                    pUp(p) = q;
                    berhasil = true;
                }
                q = next(q);
            }
        }
        p = next(p);
    }
}

void showinfoBarangDariUserTertentu(ListRelasi LR, int idUser) {
    address_Relasi p;
    bool found = false;
    int count = 0;
    p = first(LR);

    cout << ">> Mencari Data User Dan Data Barang..." << endl;
    cout << ">> Menampilkan Data Barang Yang dibeli User Dengan ID: " << idUser << "      " << endl;
    cout << "+------------------------------------------------------------------------------+" << endl << endl;

    while (p != NULL) {
        if (info(pUp(p)).ID == idUser) {
            cout << " ID            : " << info(pDown(p)).ID << endl;
            cout << " NAMA BARANG   : " << info(pDown(p)).NamaBarang << endl;
            cout << " JENIS BARANG  : " << info(pDown(p)).jenisBarang << endl << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            found = true;
            count++;
            p = next(p);
        } else {
            p = next(p);
        }
    }

    if (!found) {
        cout << ">> Data User Tidak Ditemukan Dengan Id Barang Tersebut!" << endl;
        cout << "+------------------------------------------------------------------------------+" << endl;
    } else {
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << " Jumlah Barang Yang Dibeli Oleh User Dengan ID: " << idUser
             << " Adalah Sebanyak: " << count << " Barang" << endl;
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << endl;
    }
}

void showinfoUserDariBarangTertentu(ListRelasi LR, int idBarang) {
    address_Relasi p;
    bool found = false;
    int count = 0;
    p = first(LR);

    cout << ">> Mencari Data User Dan Data Barang ..." << endl;
    cout << ">> Menampilkan Data User Yang Membeli Barang Dengan ID: " << idBarang << "      " << endl;
    cout << "+------------------------------------------------------------------------------+" << endl << endl;

    while (p != NULL) {
        if (info(pDown(p)).ID == idBarang) {
            cout << " ID             : " << info(pUp(p)).ID << endl;
            cout << " NAMA USER      : " << info(pUp(p)).Nama << endl;
            cout << " Asal           : " << info(pUp(p)).Lokasi << endl << endl;
            cout << "+------------------------------------------------------------------------------+" << endl;
            cout << endl;
            found = true;
            count++;
            p = next(p);
        } else {
            p = next(p);
        }
    }

    if (!found) {
        cout << ">> Data Barang Tidak Ditemukan Dengan Id User Tersebut!" << endl;
        cout << "+------------------------------------------------------------------------------+" << endl;
    } else {
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << "  Jumlah User Yang Membeli Barang Dengan ID: " << idBarang
             << " Adalah Sebanyak: " << count << " User" << endl;
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << endl;
    }
}

void menu(int &pilih) {
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
}
