/*
  符号無し整数を左右にシフトした値が。2乗のべき乗での乗算や除算と等しくなることを確認するプログラムを作成せよ
*/
#include <stdio.h>

#define TRY               /* TRY-CATCH */
#define THROW(name)       goto TRY_TAG_ERROR_##name /* gotoを使わないと実装出来なかった */
#define CATCH(name, last) goto TRY_TAG_RESUME_##last; TRY_TAG_ERROR_##name:
#define FINALLY(last)     TRY_TAG_RESUME_##last:

/* このままでは汎用性が低い。scanfの実装を見て作り直す */
int unsigned_scanf();

void print_bit_shift();

int main(argc, argv)
	int argc;
	char *argv[];
{
	unsigned num;
    const unsigned *p = &num;

	TRY {
		printf("Unsigned Number: ");
		if(!unsigned_scanf(p)) THROW(NOT_NUM);
	}

	print_bit_shift(num);
 	
	CATCH(NOT_NUM, END) {
		puts("You should enter a number!!");
		return 1;
	}
	
	FINALLY(END) { }
	
	return 0;
}

int unsigned_scanf(p)
	const unsigned *p;
{
	const int check = scanf("%u", p);
	while (getchar() != '\n')
		;
	return check;
}

void print_bit_shift(num)
	const unsigned num;
{
	printf("*2 :%u :%u\n/2 :%u :%u\n", num << 1, num * 2, num >> 1, num / 2);
}
