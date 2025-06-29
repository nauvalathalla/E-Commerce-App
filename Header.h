#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using namespace std;

#define BLUE "\033[34m"
#define BOLD "\033[1m"

#define Nil NULL
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define pUp(P)  P->pUp
#define pDown(P) P->pDown

struct User {
    int ID;
    string Nama;
    string Lokasi;
};

struct Barang {
    int ID;
    string NamaBarang;
    string jenisBarang;
};

typedef User infotypeUser;
typedef Barang infotypeBarang;

typedef struct ElmUser *address_User;
typedef struct ElmBarang *address_Barang;
typedef struct ElmRelasi *address_Relasi;

struct ElmUser {
    infotypeUser info;
    address_User next;
};

struct ElmBarang {
    infotypeBarang info;
    address_Barang next;
    address_Barang prev;
};

struct ElmRelasi {
    address_User pUp;
    address_Barang pDown;
    address_Relasi next;
};

struct ListUser {
    address_User first;
};

struct ListBarang {
    address_Barang first;
    address_Barang last;
};

struct ListRelasi {
    address_Relasi first;
};

void createList_User(ListUser &LU);
void createList_Barang(ListBarang &LB);
void createList_Relasi(ListRelasi &LR);

address_User createElmUser(infotypeUser InfoUser);
address_Barang createElmBarang(infotypeBarang InfoBarang);
address_Relasi createElmRelasi();

void insertFirstUser(ListUser &LU, address_User P);
void insertLastUser(ListUser &LU, address_User p);
void insertAfterUser(ListUser &LU, address_User prec, address_User p);

void insertFirstBarang(ListBarang &LB, address_Barang P);
void insertAfterBarang(ListBarang &LB, address_Barang prec, address_Barang p);
void insertLastBarang(ListBarang &LB, address_Barang p);

void insertFirstConnection(ListRelasi &LR, address_Relasi p);
void insertAfterConnection(ListRelasi &LR, address_Relasi prec, address_Relasi P);
void insertLastConnection(ListRelasi &LR, address_Relasi p);

void deleteFirstParent(ListUser &LU, address_User P);
void deleteAfterParent(ListUser &LU, address_User q, address_User P);
void deleteLastParent(ListUser &LU, address_User p);
void DeleteThatParent(ListUser &LU, address_User p);

void deleteFirstChild(ListBarang &LB, address_Barang p);
void deleteLastChild(ListBarang &LB, address_Barang p);
void deleteThatChild(ListBarang &LB, address_Barang p);

void deleteFirstConnection(ListRelasi &LR, address_Relasi p);
void deleteAfterConnection(ListRelasi &LR, address_Relasi prec, address_Relasi p);
void deleteLastConnection(ListRelasi &LR, address_Relasi p);
void deleteThatConnection(ListRelasi &LR, address_Relasi prec);
void deleteBarangYangDiList(ListBarang &LB, address_Barang &P);

address_User findUser(ListUser LU, int ID);
address_Relasi findRelasi( ListRelasi LR, int IDUser, int IDBarang);
address_Barang findBarang(ListBarang LB, int ID);

void showParent(ListUser LU);
void connect(ListRelasi &LR, address_User parent, address_Barang child, address_Relasi p);
void showChild(ListBarang LB);
void showInfoRelation(ListUser LU, ListBarang LB, ListRelasi LR);

int countJumlahChildFromSpecificParent(ListRelasi LR,int ID);
int countJumlahParentFromSpecificChild(ListRelasi LR, int ID);
int countJumlahChildNoParent(ListBarang LB, ListRelasi LR);
int countJumlahParentNoChild(ListUser LU, ListRelasi LR);

void changeChildFromSpecificParent(ListBarang &LB, ListRelasi &LR,int cariUserId,  int cariBarangId, int idBarangBaru, bool &berhasil);
void changeParentFromSpecificChild(ListUser &LU, ListRelasi &LR, int cariUserId, int cariBarangId, int IdUserBaru, bool &berhasil);

void menu(int &pilih);
void showinfoBarangDariUserTertentu(ListRelasi LR,int idUser);
void showinfoUserDariBarangTertentu(ListRelasi LR,int idBarang);
void showInfoRelationChild(ListBarang LB, ListRelasi LR);
void showInfoRelationParent(ListUser LU, ListRelasi LR);

#endif // HEADER_H_INCLUDED
