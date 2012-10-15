/*
  符号無し整数ｘのposビット目からｎ個のビットを、１にした値を返す関数set_n, 0にした値を返す関数reset_n, 反転した値を返す関数inverse_nを作成せよ
*/
#include <stdio.h>

int count_bits();
int unsigned_bits();
void print_bits();
unsigned set_n();
unsigned reset_n();
unsigned inverse_n();

int main(argc, argv)
	int argc;
	char *argv[];
{
	int check, bit, sum;
	int *q = &bit, *r = &sum;
	unsigned num;
	unsigned *p = &num;

	printf("符号無し整数：");
	check = scanf("%u", p);
	while (getchar() != '\n')
		;
	if (check) {
		printf("ビット目:");
		check = scanf("%d", q);
		while (getchar() != '\n')
			;
		if (check) {
			printf("ビット数:");
			check = scanf("%d", r);
			while (getchar() != '\n')
				;
			if (check) {
				print_bits(num);
				print_bits(set_n(num, bit, sum));
				print_bits(reset_n(num, bit, sum));
				print_bits(inverse_n(num, bit, sum));
			}
		}
	}

	return 0;
}

int count_bits(x)
	unsigned x;
{
	static int count;
	if (x) {
		if (x & 1U)
			count++;
		return count_bits(x >>= 1);
	} else {
		int tmp = count;
		count = 0;
		return tmp;
	}
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

unsigned set_n(x, pos, n)
	unsigned x;
	int pos, n;
{
	if (n) 
		return set_n(x = ((x >> --pos) & 1U) ? x : x + (1U << pos), pos, --n);
	else
		return x;
}

unsigned reset_n(x, pos, n)
	unsigned x;
	int pos, n;
{
	if (n)
		return reset_n(x = ((x >> --pos) & 1U) ? x - (1U << pos) : x, pos, --n);
	else
		return x;
}

unsigned inverse_n(x, pos, n)
	unsigned x;
	int pos, n;
{
	if (n)
		return inverse_n(x = ((x >> --pos) & 1U) ? x - (1U << pos) : x + (1U << pos), pos, --n);
	else
		return x;
}
