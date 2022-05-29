#include<stdio.h>    
#include<string.h>
int Count(FILE* file,int* charNum,int* wordNum);
int main(int argc,char* argv[]){
	int charNum = 0;
	int wordNum = 0;
	FILE* file;

	file = fopen("input.txt","r");
	if(file == NULL){
		printf("�ļ�Ϊ�գ�������");
		return 0;
	}
	Count(file,&charNum,&wordNum);
	if(strcmp(argv[1], "-c") == 0){
		printf("�ַ�����%d\n",charNum);
	}else if(strcmp(argv[1], "-w") == 0){
		printf("��������%d\n",wordNum);
	}
	fclose(file);
	return 0;
}
int Count(FILE* file,int* charNum,int* wordNum){
	int flag = 0;
	char temp;
	while((temp = fgetc(file))!=EOF){
		(*charNum)++;
		if(flag==0&&(temp!=' '||temp != ',')){
			(*wordNum)++;
			flag = 1;
		}else if(temp==' '||temp == ','){
			flag=0;
		}
	}
	return 0;
}
