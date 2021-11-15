#include "MyGraph.h"


int main()
{
	MyGraph<EGraphType::Matrix, 7> ramen;

	ramen.AddEdge(0, 1, 32);
	ramen.AddEdge(0, 2, 38);
	ramen.AddEdge(0, 3, 23);
	ramen.AddEdge(0, 4, 12);
	ramen.AddEdge(0, 5, 8);

	ramen.Print();


	//false
	cout << boolalpha << ramen.IsAdjacent(0, 6) << endl;

	for (int i = 0; i < 7; ++i)
	{
		cout << ramen.GetDegree(i) << endl;
	}

}