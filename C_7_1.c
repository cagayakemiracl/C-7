/*
  符号無し整数を左右にシフトした値が。2乗のべき乗での乗算や除算と等しくなることを確認するプログラムを作成せよ
*/
#include <stdio.h>

int main(argc, argv)
	int argc;
	char *argv[];
{
	int check;
	unsigned num;
	unsigned *p = &num;

	printf("符号なし数：");
	check = scanf("%u", p);
	while (getchar() != '\n')
		;	
	if (check)
		printf("*2 :%u :%u\n/2 :%u :%u\n", num << 1, num * 2, num >> 1, num / 2);

	return 0;
}
