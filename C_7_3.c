/*
  符号無し整数ｘのposビット目を、１にした値を返す関数set, 0にした値を返す関数reset, 反転した値を返す関数inverseを作成せよ
*/
#include <stdio.h>

#define TRY               /* TRY-CATCH */
#define THROW(name)       goto TRY_TAG_ERROR_##name /* gotoを使わないと実装出来なかった */
#define CATCH(name, last) goto TRY_TAG_RESUME_##last; TRY_TAG_ERROR_##name:
#define FINALLY(last)     TRY_TAG_RESUME_##last:

/* このままでは汎用性が低い。scanfの実装を見て作り直す */
int unsigned_scanf();
int int_scanf();

int count_bits();
int unsigned_bits();
void print_bits();
unsigned set();
unsigned reset();
unsigned inverse();

int main(argc, argv)
	int argc;
	char *argv[];
{
	int bit;
	const int *q = &bit;
	unsigned num;
	const unsigned *p = &num;

	TRY {
		printf("Unsigned Number: ");
		if(!unsigned_scanf(p)) THROW(NOT_NUM);
		printf("Th Bit: ");
		if(!int_scanf(q)) THROW(NOT_NUM);
	}
	
	print_bits(num);
	print_bits(set(num, bit));
	print_bits(reset(num, bit));
	print_bits(inverse(num, bit));

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

int int_scanf(p)
	int *p;
{
	const int check = scanf("%d", p);
	while (getchar() != '\n')
		;
	return check;
}

int count_bits(x)
	unsigned x;
{
	int count;
	for (count = 0; x; x >>= 1)
		if (x & 1U) ++count;
	return count;
}

int unsigned_bits(void)
{
	return count_bits(~0U);
}

void print_bits(x)
	const unsigned x;
{
	int i;
	printf("0b");
	for (i = unsigned_bits(); i > 0; )
		putchar(((x >> --i) & 1U) ? '1' : '0');
	putchar('\n');
}

unsigned set(x, pos)
	const unsigned x;
	int pos;
{
	return x | 1 << --pos;
}

unsigned reset(x, pos)
	const unsigned x;
	int pos;
{
	return set(x, pos) ^ 1 << --pos;
}

unsigned inverse(x, pos)
	const unsigned x;
	int pos;
{
	return x ^ 1 << --pos;
}
