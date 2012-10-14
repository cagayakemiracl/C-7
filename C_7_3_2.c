/*
  符号無し整数ｘのposビット目を、１にした値を返す関数set, 0にした値を返す関数reset, 反転した値を返す関数inverseを作成せよ
*/
#include <stdio.h>

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
	int check, bit;
	int *q = &bit;
	unsigned num;
	unsigned *p = &num;

	printf("符号無し整数：");
	check = scanf("%u", p);
	while (getchar() != '\n')
		;
	if (check) {
		printf("ビット目");
		check = scanf("%d", q);
		while (getchar() != '\n')
			;
		if (check) {
			print_bits(num);
			print_bits(set(num, bit));
			print_bits(reset(num, bit));
			print_bits(inverse(num, bit));
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

unsigned set(x, pos)
	unsigned x;
	int pos;
{
	return (x >> --pos & 1U) ? x : x + (1U << pos);
}

unsigned reset(x, pos)
	unsigned x;
	int pos;
{
	return (x >> --pos & 1U) ? x - (1U << pos) : x;
}

unsigned inverse(x, pos)
	unsigned x;
	int pos;
{
	return (x >> --pos & 1U) ? x - (1U << pos) : x + (1U << pos);
}
