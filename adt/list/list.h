/* ***************** MODUL LIST BERKAIT ***************** */
/* List direpresentasi dengan pointer, First dinyatakan secara eksplisit. */

/* Konstanta */
#define Nil NULL /* address tidak terdefinisi */

typedef int infotype;

typedef struct tElmtList *address;

typedef struct {
    address First;
} List;

typedef struct tElmtList{
    infotype Info;
    address Next;
    List Child;
} ElmtList;


/* Jika L : List dan P : address (address untuk traversal), maka penulisan : */

#define First(L) ((L).First)
#define Next(P) (P)->Next
#define Child(P) (P)->Child
#define Info(P) (P)->Info

/* First(L) menjadi L.First
Next(P) menjadi P↑.Next
Info(P) menjadi P↑.Info */
/* Definisikan selektor yang tepat. */

/* PROTOTYPE */
/* ***************** TEST LIST KOSONG ***************** */
boolean IsListEmpty (List L);
/* Mengirim true jika list kosong */

/* ***************** PEMBUATAN LIST KOSONG ***************** */
void CreateList (List *L);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

/* ***************** Manajemen Memori ***************** */
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi ( address P );
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
address Search ( List L, infotype X );
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut */
/* Jika tidak ada, mengirimkan Nil */

boolean FSearch ( List L, address P );
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

address SearchPrec ( List L, infotype X );
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */

/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka mengirimkan Nil */
/* Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah
Search akan dilakukan operasi lain */

/* ***************** PRIMITIF BERDASARKAN NILAI ***************** */
/* *** PENAMBAHAN ELEMEN *** */
void InsVFirst ( List *L, infotype X );
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

void InsVLast ( List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen terakhir L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

/* *** PENGHAPUSAN ELEMEN *** */
void DelVFirst ( List *L, infotype *X);
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus : nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */

void DelVLast ( List *L, infotype *X );
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst ( List *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter ( List *L, address P, address Prec );
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast ( List *L, address P );
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/* *** PENGHAPUSAN SEBUAH ELEMEN *** */

void DeleteFirst ( List *L, address *P );
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yang baru adalah suksesor elemen pertama yang lama */

void DeleteP ( List *L, infotype X );
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P) = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DeleteLast ( List *L, address *P );
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yang lama, jika ada */

void DeleteAfter ( List *L, address *Pdel, address Prec );
/* I.S. List tidak kosong. Prec adalah anggota list L. */
/* F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus */

/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void PrintInfo ( List L );
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */

int NbElmt ( List L );
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/* *** Prekondisi untuk Max/Min/rata-rata : List tidak kosong *** */

infotype Max ( List L );
/* Mengirimkan nilai Info(P) yang maksimum */

address AdrMax ( List L );
/* Mengirimkan address P, dengan Info(P) yang bernilai maksimum */

infotype Min ( List L );
/* Mengirimkan nilai Info(P) yang minimum */

address AdrMin ( List L );
/* Mengirimkan address P, dengan Info(P) yang bernilai minimum */

float Average ( List L );
/* Mengirimkan nilai rata-rata Info(P) */

/* ***************** PROSES TERHADAP LIST ***************** */
void DeleteAll ( List *L );
/* Delete semua elemen list dan alamat elemen di-dealokasi */
/* I.S. : L terdefinisi, boleh kosong */
/* F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi */

