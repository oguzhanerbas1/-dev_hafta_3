#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �?renci yapysy
struct Ogrenci {
    int ogrenciNo;
    char ad[50];
    struct Ogrenci* next;
};

// Yeni �?renci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = NULL;

    if (head == NULL) {
        return yeniOgrenci;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeniOgrenci;

    return head;
}

// �?renci listesini ekrana yazdyran fonksiyon
void ogrenciListesiYazdir(struct Ogrenci* head) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        printf("Ogrenci No: %d, Ad: %s\n", gecici->ogrenciNo, gecici->ad);
        gecici = gecici->next;
    }
}

// �?renci silme fonksiyonu
struct Ogrenci* ogrenciSilSonraki(struct Ogrenci* head, const char* hedefAd) {
    if (head == NULL) {
        printf("Liste bo?. Silme islemi yapilamaz.\n");
        return head;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            struct Ogrenci* silinecek = gecici->next;
            gecici->next = silinecek->next;
            free(silinecek);
            printf("%s adly ogrencinin sonraki ogrencisi silindi.\n", hedefAd);
            return head;
        }
        gecici = gecici->next;
    }

    printf("%s adli ogrenci bulunamadi veya listenin sonunda bulunuyor.\n", hedefAd);
    return head;
}

int main() {
    struct Ogrenci* liste = NULL;

    // �?renci kayytlary ekleniyor
    liste = ogrenciEkle(liste, 1, "enes");
    liste = ogrenciEkle(liste, 2, "rukiye");
    liste = ogrenciEkle(liste, 3, "saliha");
    liste = ogrenciEkle(liste, 4, "koray");

    // �?renci listesini ekrana yazdyr
    printf("Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Kullanycydan silinecek �?rencinin adyny al
    char silinecekAd[50];
    printf("Hangi ogrenciden sonraki ogrenciyi silmek istersiniz? �?renci adini girin: ");
    scanf("%s", silinecekAd);

    // �?renci silme i?lemi
    liste = ogrenciSilSonraki(liste, silinecekAd);

    // G�ncellenmi? �?renci listesini ekrana yazdyr
    printf("Guncellenmis Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Belle?i temizle (serbest byrak)
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}
