#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct Information{
    char name[10];
    char address[20];
    char postalCode[10];
    char phoneNumber[11];
};
int fileLines = 1;         //全局变量，用以记录数据的数量,最后一行无换行符所以赋1
struct Information *contactInformas = NULL; //用以存储数据文件中的数据。

void readAddressDatas();
void displayAddressBook();
int main()
{
    readAddressDatas();
    int i;
    for(i=0;i<fileLines;i++){
        printf("%s\t%s\t%s\t%s\n",contactInformas[i].name,contactInformas[i].address,
               contactInformas[i].postalCode,contactInformas[i].phoneNumber);
    }
}
void readAddressDatas(){
    char ch,name[10],address[100],postalCode[10],phoneNumber[20];

    FILE *fileRead = NULL;
    fileRead = fopen("AddressBookDatas.txt","r");
    //读取文件行数,为了存储信息变量申请空间
    while((ch=fgetc(fileRead)) != EOF)
        if(ch == '\n')
            fileLines++;
    contactInformas = (struct Information*)malloc(fileLines*sizeof(struct Information));

    fseek(fileRead,0,SEEK_SET);//读取完行数后将文件指针指向地址初始化
    //读取通讯录信息
    int currLine = 0;
    while(fscanf(fileRead,"%s%s%s%s",name,address,postalCode,phoneNumber) != EOF){
        strcpy(contactInformas[currLine].name,name);
        strcpy(contactInformas[currLine].address,address);
        strcpy(contactInformas[currLine].postalCode,postalCode);
        strcpy(contactInformas[currLine].phoneNumber,phoneNumber);
        currLine++;
    }
}
void displayAddressBook(struct Information *contactInformas){

}
