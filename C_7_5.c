/*
  符号なし整数に対する算術演算が、オーバーフローを起こさないことを確認するプログラムを作成せよ
*/
#include <stdio.h>
#include <limits.h>

#define TRY               /* TRY-CATCH */
#define THROW(name)       goto TRY_TAG_ERROR_##name /* gotoを使わないと実装出来なかった */
#define CATCH(name, last) goto TRY_TAG_RESUME_##last; TRY_TAG_ERROR_##name:
#define FINALLY(last)     TRY_TAG_RESUME_##last:

/* このままでは汎用性が低い。scanfの実装を見て作り直す */
int unsigned_scanf();

void print_unsigned_over();

int main(argc, argv)
	int argc;
	char *argv[];
{
	const unsigned num = UINT_MAX;
	unsigned sum;
	const unsigned *p = &sum;
	
	TRY {
		if(!unsigned_scanf(p)) THROW(NOT_NUM);
	}

	print_unsigned_over(num, sum);

	CATCH(NOT_NUM, END) {
		puts("You should enter a number!!");
		return 1;
	}
	
	FINALLY(END) { }

	return 0;
}

int unsigned_scanf(p)
	unsigned *p;
{
	const int check = scanf("%u", p);
	while (getchar() != '\n')
		;
	return check;
}

void print_unsigned_over(num, sum)
	const unsigned num, sum;
{
	printf("%u\n%u\n", num, num + sum);
}
