/*
  符号なし整数ｘを右のｎビット回転した値を返す関数rrotateと、左のｎビット回転した値を返す関数lrotateを作成せよ
*/
#include <stdio.h>

int count_bits();
int unsigned_bits();
void print_bits();
unsigned rrotate();
unsigned lrotate();

int main(argc, argv)
	int argc;
	char *argv[];
{
	int check, bit;
	int *q = &bit;
	unsigned num;
	unsigned *p = &num;

	printf("符号なし整数");
	check = scanf("%u", p);
	while (getchar() != '\n')
		;	
	if (check) {
		printf("ビット数");
		check = scanf("%d", q);
		while (getchar() != '\n')
			;
		if (check) {
			print_bits(num);
			print_bits(rrotate(num, bit));
			print_bits(lrotate(num, bit));
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

unsigned rrotate(x, n)
	unsigned x;
	int n;
{
	return x >> n | x << (unsigned_bits() - n);
}

unsigned lrotate(x, n)
	unsigned x;
	int n;
{
	return x << n | x >> (unsigned_bits() - n);
}