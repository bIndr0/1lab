#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "bd.h"

int n;

int main(){

        int y,x = 1;
        for(int i = 0; i < x; i++){
                Menu();
                scanf("%d", &y);
                if(y == 1){
                        Printf();
                }
                if(y == 2){
                        Scanf();
                }
                if(y == 3){
                        SeekClient();
                }
                if(y == 4){
                        SeekCall();
                }
                if(y == 5){
                        SeekBrand();
                }
                if(y == 6){
                        SeekStatus();
                }
                if(y == 7){
                        Del();
                }
                if(y == 8){
                        Edit();
                }
                if(y == 9){                    
                        Save();
                }
                if(y == 0){
                	Load();
                }
                if(y == 2077){
                	return 0;
                }
                x ++;
        }
}
