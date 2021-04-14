#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct bd{
	char client[40];
	char call[15];
	char brand[40];
	char status[40];
};
int j;
struct bd watch[10];


void Printf(void){
	int i;
	
	for(i = 0; i<j; i++)
	printf("%s  %s  %s %s \n", watch[i].client, watch[i].call, watch[i].brand, watch[i].status);
}

void Scanf(void){
	printf("\nВведите имя клиента -> ");
	scanf("%s", watch[j].client);
	
	printf("Введите контактный телефон -> ");
	scanf("%s", watch[j].call);
	
	printf("Введите марку часов -> ");
	scanf("%s", watch[j].brand);
	
	printf("Введите состояние часов -> ");
	scanf("%s", watch[j].status);
	
	j ++;
}

void Del(void){
	int i;
	
	printf("\nВведите номер удаляемого элемента -> ");
	scanf("%d", &i);
	
	if(i < 1 || i > j){
		fprintf(stderr, "Элемент с номером %d не существует\n", i);
		return;
	}
	
	for (i --; i < j-1 ; i++)
		watch[i] = watch[i+1];
	j --;	
}
void Edit(void){
	int i;
	
	printf("\nВведите номер редактируемого элемента -> ");
	scanf("%d", &i);
	
	if(i < 1 || i > j){
		fprintf(stderr, "Элемент с номером %d не существует\n", i);
		return;
	}
	
	printf("\nВведите имя клиента -> ");
	scanf("%s", watch[i-1].client);
	
	printf("Введите контактный телефон -> ");
	scanf("%s", watch[i-1].call);
	
	printf("Введите марку часов -> ");
	scanf("%s", watch[i-1].brand);
	
	printf("Введите состояние часов -> ");
	scanf("%s", watch[i-1].status);
}
void Save(void){
	FILE *F;
	int i;
	char fname[40];
	printf("Введите название сохранения\n");
	scanf("%s", fname);
	if ((F = fopen("fname" , "w")) == NULL){
		fprintf(stderr, "Невозможно открыть для записи файл 'BDwatch.txt'\n");
		return;
	}
	fscanf(F, "%d\n", &j);
	for (i = 0; i < j; i ++)
		fprintf(F, "%s  %s  %s %s\n", watch[i].client, watch[i].call, watch[i].brand, watch[i].status);

	fclose(F);
}
void Load(void){
	FILE*F;
	int i;
	char fname[40];
	printf("Введите название сохранения\n");
	scanf("%s", fname);
	if ((F = fopen("fname" , "r")) == NULL){
		fprintf(stderr, "Невозможно открыть для чтения файл 'BDwatch.txt'\n");
		return;
	}
	fscanf(F, "%d", &j);
	for (i = 0; i < j; i ++)
		fscanf(F,"%s%s%s%s", watch[i].client, watch[i].call, watch[i].brand, watch[i].status);

	fclose(F);
}
void SeekClient(void){
	char m[40];
	int n = 0;
	printf("\nВведите имя клиента -> ");
	scanf("%s",m);
	for(int i = 0;i < j;i ++){
		if(strcmp(m , watch[i].client) == 0){
			printf("%s  %s  %s %s \n", watch[i].client, watch[i].call, watch[i].brand, watch[i].status);
			n++;
		}	
	}
	if(n == 0)
		printf("Ничего не найдено");
	return;
}		
void SeekCall(void){
	char m[15];
	int n = 0;
	printf("\nВведите контактный телефон клиента - > ");
	scanf("%s",m);
	for(int i = 0;i < j;i ++){
		if(strcmp(m , watch[i].call) == 0){
			printf("%s  %s  %s %s \n", watch[i].client, watch[i].call, watch[i].brand, watch[i].status);
			n++;
		}	
	}
	if(n == 0)
		printf("Ничего не найдено");
	return;
}			
void SeekBrand(void){
	char m[40];
	int n = 0;
	printf("\nВведите марку часов клиента -> ");
	scanf("%s",m);
	for(int i = 0;i < j;i ++){
		if(strcmp(m , watch[i].brand) == 0){
			printf("%s  %s  %s %s \n", watch[i].client, watch[i].call, watch[i].brand, watch[i].status);
			n++;
		}	
	}
	if(n == 0)
		printf("Ничего не найдено");
	return;
}
void SeekStatus(void){
	char m[40];
	int n = 0;
	printf("\nВведите состояние часов клиента -> ");
	scanf("%s",m);
	for(int i = 0;i < j;i ++){
		if(strcmp(m , watch[i].brand) == 0){
			printf("%s  %s  %s %s \n", watch[i].client, watch[i].call, watch[i].brand, watch[i].status);
			n++;
		}	
	}
	if(n == 0)
		printf("Ничего не найдено");
	return;
}
int Menu(){	
	printf("\n\nМастерская часов\n 1. Просмотреть БД\n 2. Добавить клиента\n 3. Поиск по владельцу\n 4. Поиск по контактному телефону\n 5. Поиск по марке часов\n 6. Поиск по состоянию часов\n 7. Удалить клиента\n 8. Редактировать БД\n 9. Сохранить бузу данных\n 0. Загрузить базу данных\n 2077. Выход\n ->");
}
