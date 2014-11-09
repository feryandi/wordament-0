/* **** **** **** **** **** **** **** **** **** ***** *\
|                                                      |
|    W    O    R    D    A    M    E    N    T   ZERO  |
|                                                      |
\* **** **** **** **** **** **** **** **** **** ***** */

========================================================
Tugas Besar Alstrukdat 2014
Code Copyright: Group 3 K-2 IF 2013
========================================================

--- --- --- --- --- --- --- --- --- --- --- --- --- ---
1. STRUKTUR
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
Struktur program dibagi menjadi 4 bagian (folder)

a. adt - berisi ADT yang digunakan dalam program

b. module - berisi program baru (yang menggunakan adt) 
            yang akan digabungkan menjadi game utuh

c. res - berisi data yang diberikan oleh spek seperti 
         jenis board dan kamus kata yang digunakan

d. saves - berisi data simpanan yang digenerate dari 
           user dan dapat dipanggil lagi jika dibutuhkan


--- --- --- --- --- --- --- --- --- --- --- --- --- ---
2. ADT
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
Folder ADT berisi ADT yang digunakan dalam rangkaian 
program.

Didalam folder ADT ini berisi folder-folder yang diberi
nama sesuai dengan jenis atau kegunaan dari ADT tersebut


--- --- --- --- --- --- --- --- --- --- --- --- --- ---
3. MODULE
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
Folder module adalah file-file bentukan dari ADT yang
akan digunakan dalam driver akhir pada permainan.

Penamaan disesuaikan dengan fungsi dari file tersebut.

a. save.c - menyimpan data dari masukkan pengguna, atau
            user-generated, kedalam file .txt di dalam
            folder saves

b. load.c - mengambil data dari folder saves sesuai deng
            an permintaan

c. word.c - berisi cara kerja permainan dan cara mengambil
            kata yang dibentuk oleh user ke dalam stack

d. dict.c - mengambil kamus, dan juga membentuknya. Berisi
	    juga fungsi hash yang digunakan serta pencarian
	    hash suatu kata

e. auth.c - berisi fungsi untuk memvalidasi suatu login dan
	    register

NOTE: 
Gunakan global.h untuk menambah variabel global, 
fungsi baru atau ADT baru agar tertata rapi.

Sehingga ditiap file .c yang ada di module hanya meng-
include file global.c (kecuali driver, yang membutuhkan
file *.c lainnya)


--- --- --- --- --- --- --- --- --- --- --- --- --- ---
4. RES
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
Berisi file dari spek yang harus dan akan digunakan.


--- --- --- --- --- --- --- --- --- --- --- --- --- ---
3. SAVES
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
Terdiri dari 11 folder, 10 adalah folder berdasarkan 
board dan 1 adalah folder debug atau untuk test purpose.

Didalam folder tersebut terdapat folder lagi yakni:
highscore dan words.

Dimasing-masing folder, akan terdapat file txt yang nama
nya merupakan nama user yang memiliki data tersebut.
contoh: feryandi.txt

File txt didalam folder highscore akan mempunyai format
sebagai berikut:
<score> <dd> <mm> <yy> <hh> <MM>
<score> <dd> <mm> <yy> <hh> <MM>
.

File txt didalam folder words akan mempunyai format
sebagai berikut:
<kata yang pernah ditebak>
<kata yang pernah ditebak>
<kata yang pernah ditebak>
.

--- --- --- --- --- --- --- --- --- --- --- --- --- ---
4. UI
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
Berisi cara kerja user-interface dan pembuatannya.


--- --- --- --- --- --- --- --- --- --- --- --- --- ---
5. DISCLAIMER
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
Silahkan gunakan file ini sebagai salah satu bagian
dari changelog sehingga memudahkan pengkodingan bersama.


--- --- --- --- --- --- --- --- --- --- --- --- --- ---
6. RELEASE(S)
--- --- --- --- --- --- --- --- --- --- --- --- --- ---
ALPHA STAGE
v0.1 (7/11/2014)


--- --- --- --- --- END OF FILE --- --- --- --- ---
