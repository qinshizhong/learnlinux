#define ACCUM(x, y)		((x) += (y))

int main(void)
{
	int a = 0, b = 0, c = 0;	
	
	for (int i = 0; i < 300; ++i)
	{
		ACCUM(a, i);
		ACCUM(b, a);
		ACCUM(c, b);
	}

	return 0;
}
