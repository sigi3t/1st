#include "stdio.h"
#include "stdlib.h"
#define len 255

void getline(char line[], int maxline);

int main(int argc, char *argv[]){
	char str[len];
	char code[len];
	int codebook;
	int cheak[len];

	printf("平文を入力: ");
	getline(str, len);  //strに文字列を格納  

	int i = 0;
	while(str[i] != '\0'){ // 改行まで処理する
		cheak[i] = str[i];

		if(97 <= cheak[i]){ // 小文字英数を変換
			codebook = (str[i] - 'a' + atoi(argv[1])) % 26; // 引数だけ文字をずらす
			code[i]  = 'a' + codebook;
		} else if(65 <= cheak[i] && cheak[i] <= 90){ // 大文字英数を変換
			codebook = (str[i] - 'A' + atoi(argv[1])) % 26; // 引数だけ文字をずらす
			code[i]  = 'A' + codebook;
		} else if(48 <= cheak[i] && cheak[i] <= 57){ // 数字を変換
			codebook = (str[i] - '0' + atoi(argv[1])) % 10; // 引数だけ文字をずらす
			code[i]  = '0' + codebook;
		} else { // スペースなど他の文字はそのまま表示する
			code[i] = str[i];
		}
		i++;
	}
	code[i] = '\0';
	printf("暗号文: %s\n",code);

	return 0;
}

// １文字ずつ標準入力
void getline(char s[], int lim){  
    int c, i;   //getcharの受け取り用変数c、ループ用変数i  
      
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n'; ++i) s[i] = c;  
      
    s[i] = '\0';  
}  