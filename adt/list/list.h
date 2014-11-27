/* ***************** MODUL LIST BERKAIT ***************** */
/* List direpresentasi dengan pointer, First dinyatakan secara eksplisit. */

/* Konstanta */
#define NilAdd NULL /* addressL tidak terdefinisi */

typedef int infotypeL;

typedef struct tElmtList *addressL;

typedef struct {
    addressL First;
} List;

typedef struct tElmtList{
    infotypeL Info;
    addressL Next;
    List Child;
} ElmtList;


/* Jika L : List dan P : addressL (addressL untuk traversal), maka penulisan : */

#define FirstL(L) ((L).First)
#define NextL(P) (P)->Next
#define ChildL(P) (P)->Child
#define InfoL(P) (P)->Info

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
addressL Alokasi (infotypeL X);
/* Mengirimkan addressL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressL tidak Nil, dan misalnya menghasilkan P, maka
Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi ( addressL P );
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressL P */

/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
addressL Search ( List L, infotypeL X );
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan addressL elemen tersebut */
/* Jika tidak ada, mengirimkan Nil */

boolean FSearch ( List L, addressL P );
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

addressL SearchPrec ( List L, infotypeL X );
/* Mengirimkan addressL elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan addressL Prec, dengan Next(Prec) = P dan Info(P) = X */

/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka mengirimkan Nil */
/* Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah
Search akan dilakukan operasi lain */

/* ***************** PRIMITIF BERDASARKAN NILAI ***************** */
/* *** PENAMBAHAN ELEMEN *** */
void InsVFirst ( List *L, infotypeL X );
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

void InsVLast ( List *L, infotypeL X);
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen terakhir L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

/* *** PENGHAPUSAN ELEMEN *** */
void DelVFirst ( List *L, infotypeL *X);
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus : nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */

void DelVLast ( List *L, infotypeL *X );
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst ( List *L, addressL P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-addressL P sebagai elemen pertama */

void InsertAfter ( List *L, addressL P, addressL Prec );
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast ( List *L, addressL P );
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/* *** PENGHAPUSAN SEBUAH ELEMEN *** */

void DeleteFirst ( List *L, addressL *P );
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yang baru adalah suksesor elemen pertama yang lama */

void DeleteP ( List *L, infotypeL X );
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressL P, dengan Info(P) = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DeleteLast ( List *L, addressL *P );
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yang lama, jika ada */

void DeleteAfter ( List *L, addressL *Pdel, addressL Prec );
/* I.S. List tidak kosong. Prec adalah anggota list L. */
/* F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus */

/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void PrintInfo ( List L );
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */

int NbElmtL ( List L );
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/* *** Prekondisi untuk Max/Min/rata-rata : List tidak kosong *** */

infotypeL Max ( List L );
/* Mengirimkan nilai Info(P) yang maksimum */

addressL AdrMax ( List L );
/* Mengirimkan addressL P, dengan Info(P) yang bernilai maksimum */

infotypeL Min ( List L );
/* Mengirimkan nilai Info(P) yang minimum */

addressL AdrMin ( List L );
/* Mengirimkan addressL P, dengan Info(P) yang bernilai minimum */

float Average ( List L );
/* Mengirimkan nilai rata-rata Info(P) */

/* ***************** PROSES TERHADAP LIST ***************** */
void DeleteAll ( List *L );
/* Delete semua elemen list dan alamat elemen di-dealokasi */
/* I.S. : L terdefinisi, boleh kosong */
/* F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi */

