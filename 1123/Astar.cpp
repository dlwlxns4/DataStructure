#include <set>
#include "Set.h"

using namespace std;

int main()
{
	set<int> set = { 8,3,2,5,4,10,14,11,16 };
	for (int data : set)
		cout << data << " ";
	cout << endl;

	if (set.end() != set.find(2))
		cout << " Found 2\n";

	if (set.end() == set.find(13))
		cout << " NotFound 13\n";

}