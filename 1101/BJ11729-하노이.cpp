//#include <stdio.h>
//
//using namespace std;
//
//
//
//void PrintHanoi(int count, int s, int m, int t)
//{
//
//	if (count == 1)
//	{
//		printf("%d %d\n", s, t);
//		return;
//	}
//
//	PrintHanoi(count - 1, s, t, m);
//	printf("%d %d\n", s, t);
//	PrintHanoi(count - 1, m, s, t);
//}
//
//int CountHanoi2(int count, int s, int m, int t)
//{
//	if (count == 1)
//	{
//		return 1;
//	}
//
//	return CountHanoi2(count - 1, s, t, m)+CountHanoi2(1, s, m, t)+CountHanoi2(count - 1, m, s, t);
//}
//
//int main()
//{
//	int N = 0;
//	
//	scanf_s("%d", &N);
//
//	printf("%d\n", CountHanoi2(N, 1, 2, 3));
//	PrintHanoi(N, 1, 2, 3);
//
//}