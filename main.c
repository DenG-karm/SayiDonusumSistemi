#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strev (char* str);

char* decimaltobinary(int decimal) {
    char* binary = (char*)malloc(33);
    int i = 0;
    while (decimal) {
        binary[i++] = '0' + (decimal & 1);
        decimal >>= 1;
    }
    binary[i]= '\0';
    strrev(binary);
    return binary;

}


int binarytodecimal(char binary[]) {
    int decimal = 0;
    int lenght = strlen(binary);
    for (int i = 0; i<lenght; i++) {
        decimal = decimal * 2 + (binary[i]-'0');
    }
    return decimal;
}


char* decimaltooctal(int decimal) {
    char* octal = (char*)malloc(12);
    if (octal == NULL) {
        printf("Bellek ayirma islemi basarisiz oldu!\n");
        exit(1);
    }
    sprintf(octal,"%o",decimal);
    return octal;
}


int octaltodecimal(char octal[]) {
    int decimal =0;
    int length = strlen(octal);
    for (int i = 0; i< length; i++) {
        decimal=decimal*8+(octal[i]-'0');
    }
    return decimal;
}


char* hexadecimaltobinary(char hex[]) {
    unsigned int hexnum;
    sscanf(hex,"%x",&hexnum);
    char binary[33] = "";
    int i = 0;
    while (hexnum) {
        binary[i++] = '0' + hexnum % 2;
        hexnum/=2;
    }
    binary[i] = '\0';
    strrev(binary);

    return strdup(binary);
}

char* binarytohexadecimal(char binary[]) {
    int length=strlen(binary);
    int padding = (4-(length % 4)) %4 ;
    char paddedbinary[129];
    memset(paddedbinary,'0',padding);
    strcpy(paddedbinary + padding, binary);
    char* binaryhexdigits[]        = { "0000", "0001", "0010", "0011", "0100", "0101",
            "0110", "0111", "1000", "1001", "1010", "1011",
            "1100", "1101", "1110", "1111" };
    char hexadecimal[33]= "";
    for (int i = 0; i<length+padding; i+=4) {
        char group[5];
        strncpy(group,paddedbinary+i,4);
        group[4]='\0';
        for (int j = 0; j<16; j++) {
            if (strcmp(group,binaryhexdigits[j]) ==0){
                char hexdigit[2];
                sprintf(hexdigit,"%X",j);
                strcat(hexadecimal,hexdigit);
                break;
            }
        }
    }
return strdup(hexadecimal);

}

int main() {
    int choice;
    while (1) {
        printf("\nMenu\n");
        printf("1.Ondaliktan ikiliye\n");
        printf("2.ikiliden ondaliga\n");
        printf("3.Ondaliktan sekizlige\n");
        printf("4.Sekizligten ondaliga \n");
        printf("5.Onaltiliktan ikiliye\n");
        printf("6.Ikiliden onaltiliga\n");
        printf("7.Exit\n");
        printf("Seciminizi yapiniz:\n");
        scanf("%d", &choice);
        if (choice == 7) {
            printf("Cikis yapiliyor..");
            break;
        }
        char input[100];
        switch (choice) {

            case 1:
                printf("Bir ondalik sayi giriniz:");
            scanf("%d",&choice);
            char* result = decimaltobinary(choice);;
            printf("Ondaliktan ikilige : %s\n",result);
            free(result);
            break;
            case 2:
                printf("Ikilik bir sayi giriniz:");
            scanf("%s",input);
            int binaryresult = binarytodecimal(input);
            printf("Ikilikten ondaliga : %d\n",binaryresult);
            break;
            case 3:
                printf("Bir ondalik sayi giriniz:");
            scanf("%d",&choice);
            result=decimaltooctal(choice);
            printf("Ondaliktan sekizlige : %s\n",result);
            free(result);
            break;
            case 4:
                printf("Sekizlik bir sayi giriniz:");
            scanf("%s",input);
            int octalresult =  octaltodecimal(input);
            printf("Sekizlikten ondaliga : %d\n",octalresult);
            break;
            case 5:
                printf("Bir onaltilik sayi giriniz:");
            scanf("%s",input);
            result = hexadecimaltobinary(input);
            printf("Onaltiliktan ikilige : %s\n",result);
            free(result);
            break;
            case 6:
                printf("Bir ikilik sayi giriniz:");
            scanf("%s",input);
            result = binarytohexadecimal(input);
            printf("Ikilikten onaltiliga : %s\n",result);
            free(result);
            break;
            default:
                printf("Gecersiz secim yaptiniz..Lutfen tekrar deneyiniz..\n");
        }
    }
    return 0;
}

void strev(char* str) {
    int i =0;
    int j = strlen(str) - 1;
    while (i<j) {
        char c = str[i];
        str[i]=str[j];
        str[j]=c;
        i++;
        j--;

    }
}