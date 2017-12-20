#include <stdio.h>
#include <string.h>

#define STR 128

void lan_dec(char bf[] , char fname[] ,int n);

/*************************************************/
/*                                               
/*				���C���֐�
/*                                               
/*************************************************/
int main(void){
	
	int i = 0;
	int ch;
	FILE *fp;
	char fname[STR];                                        /*�t�@�C�����i�[�p�̔z��*/
	char bef[STR];                                          /*�����O������̊i�[�p�z��*/
	
	printf("�t�@�C�����F");
	scanf("%s",fname);
	
	if((fp = fopen(fname,"rb")) == NULL){
		printf("\a�t�@�C�����I�[�v���ł��܂���\n");         /*�G���[��*/
	}
	else{
		printf("�����O�̕�����F");
		while((ch = fgetc(fp)) != EOF){                     /*�I�[�����������܂ŕ�����\��*/
			putchar(ch);
			bef[i] = ch;
			i++;
		}
		fclose(fp);
		printf("\n");
		
	}
	putchar('\n');
	lan_dec(bef,fname,i);
	
	return 0;
}
/*************************************************/
/*                                               
/*	�f�R�[�h�E�\�������A�t�@�C���������ݏ���
/*                                   
/*************************************************/
void lan_dec(char bf[] , char fname[] ,int n){
	
	int i = 0;
	int cnt = 0;
	FILE *fp;
	fp = fopen(fname,"wb");
	
	printf("������̕�����F");
	if(fp == NULL){
		printf("\a�t�@�C�����I�[�v���ł��܂���\n");
	}
	for(i = 0 ; i < n; i++){
		if(bf[i] == '@'){
				cnt = bf[i + 1] - '0';                      /*�ϐ�cnt��@�̎��̐������i�[*/
				
				while(cnt > 1){                             /*@�̎��̐��������[�v*/
					putchar(bf[i + 2]);
					cnt--;
					fputc(bf[i + 2], fp );
				}
				i = i + 1;
		}
		else{
			putchar(bf[i]);
			fputc(bf[i] , fp);
		}
	}
	fclose(fp);

}
