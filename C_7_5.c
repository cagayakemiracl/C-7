/*
  符号なし整数に対する算術演算が、オーバーフローを起こさないことを確認するプログラムを作成せよ
*/
#include <stdio.h>
#include <limits.h>

int main(argc, argv)
	int argc;
	char *argv[];
{
	unsigned num = UINT_MAX, sum;
	unsigned *p = &sum;
	int check;

	check = scanf("%u", p);
	while (getchar() != '\n')
		;
	if (check)
		printf("%u\n%u\n", num, num + sum);

	return 0;
}
