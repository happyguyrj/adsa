#include <iostream>
#include "ufds.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	UFDS set(4);

	set.union_set(0,1);
	set.union_set(0,2);
	set.union_set(2,3);

	cout<<set.num_disjoint_sets()<<endl;

	return 0;
}
