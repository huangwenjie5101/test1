#include<stdio.h>
int main(){
	FILE* fp = fopen("configure.txt", "rb+");
    int arr[20][4][4];
    /*for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 4; j++) {
             for (int k = 0; k < 4; k++) {
                 fread(&arr[i][j][k], sizeof(int), 1, fp);
              }
        }
    }*/
    fread(arr,sizeof(int),320,fp);
    fclose(fp);
	
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				printf("%d", arr[i][j][k]);
			}
			putchar('\n');
		}
		putchar('\n'); 
	}
} 
