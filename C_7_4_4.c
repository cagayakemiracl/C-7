/*
  符号無し整数ｘのposビット目からｎ個のビットを、１にした値を返す関数set_n, 0にした値を返す関数reset_n, 反転した値を返す関数inverse_nを作成せよ
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
unsigned set_n();
unsigned reset_n();
unsigned inverse_n();

int main(argc, argv)
	int argc;
	char *argv[];
{
	int bit, sum;
	int *q = &bit, *r = &sum;
	unsigned num;
	unsigned *p = &num;
	
	TRY {
		printf("Unsigned Number: ");
		if(!unsigned_scanf(p)) THROW(NOT_NUM);
		printf("Th Bits: ");
		if(!int_scanf(q)) THROW(NOT_NUM);
		printf("Number Of Bits: ");
		if(!int_scanf(r)) THROW(NOT_NUM);
	}

	print_bits(num);
	print_bits(set_n(num, bit, sum));
	print_bits(reset_n(num, bit, sum));
	print_bits(inverse_n(num, bit, sum));
	
	CATCH(NOT_NUM, END) {
		puts("You should enter a number!!");
	}
	
	FINALLY(END) {
		return 0;
	}
}

int unsigned_scanf(p)
	unsigned *p;
{
	int check;
	check = scanf("%u", p);
	while (getchar() != '\n')
		;
	return check;
}

int int_scanf(p)
	unsigned *p;
{
	int check;
	check = scanf("%d", p);
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
	unsigned x;
{
	int i;
	printf("0b");
	for (i = unsigned_bits(); i > 0; )
		putchar(((x >> --i) & 1U) ? '1' : '0');
	putchar('\n');
}

unsigned set(x, pos)
	unsigned x;
	int pos;
{
	return x | 1 << --pos;
}

unsigned reset(x, pos)
	unsigned x;
	int pos;
{
	return set(x, pos) ^ 1 << --pos;
}

unsigned inverse(x, pos)
	unsigned x;
	int pos;
{
	return x ^ 1 << --pos;
}

unsigned set_n(x, pos, n)
	unsigned x;
	int pos, n;
{
	if (n) 
		return set_n(set(x, pos), --pos, --n); 
	else
		return x;
}

unsigned reset_n(x, pos, n)
	unsigned x;
	int pos, n;
{
	if (n)
		return reset_n(reset(x, pos), --pos, --n);
	else
		return x;
}

unsigned inverse_n(x, pos, n)
	unsigned x;
	int pos, n;
{
	if (n)
		return inverse_n(inverse(x, pos), --pos, --n);
	else
		return x;
}
