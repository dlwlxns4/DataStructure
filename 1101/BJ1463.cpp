#include <stdio.h>
#include <iostream>

using namespace std;


int recursive(int n)
{
	if (n <= 1)
	{
		return 0;
	}

	int s1 = recursive(n / 3) + n % 3 + 1;
	int s2 = recursive(n / 2) + n % 2 + 1;


	cout << s1 << " " << s2 << endl;
	return (s1 < s2 ) ? s1 : s2;
}

int main()
{

	int N = 0;

	scanf_s("%d", &N);

	printf("%d", recursive(N));
}