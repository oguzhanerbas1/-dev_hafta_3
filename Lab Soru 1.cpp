#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* teksayi(struct node* head, int data) { //tek say� girilirse ca��r�lan fonksiyon
    struct node* node2 = (struct node*)malloc(sizeof(struct node));
    node2->data = data;
    node2->next = head;
    return node2;
}

struct node* ciftsayi(struct node* head, int data) {		//�ift sayi girilirse ca��r�lan fonksiyon
    struct node* node3 = (struct node*)malloc(sizeof(struct node));
    node3->data = data;
    node3->next = NULL;

    if (head == NULL)
        return node3;

    struct node* gecici = head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = node3;
    return head;
}

void yazdir(struct node* head) {   //ekrana yazd�rma i�lemi
    struct node* gecici = head;
    while (gecici != NULL) {
        printf("%d -> ", gecici->data);
        gecici = gecici->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int key;

    printf("Lutfen -1 disinda bir sayi giriniz: \n");
    printf("programin bitmesi icin -1e basiniz. \n");

    while (1) {					//say�n�n tek mi �ift mi oldugunu kontrol ediyoruz
        printf("Bir say� giriniz: ");
        scanf("%d", &key);

        if (key == -1) {
            break;
        }
        if (key % 2 == 1) {
            head = teksayi(head, key);
        } else {
            head = ciftsayi(head, key);
        }
    }

    printf("Sonu�: ");
    yazdir(head);

    // Serbest b�rakma i�lemi		
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
