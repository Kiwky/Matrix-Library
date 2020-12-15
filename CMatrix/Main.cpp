#include <iostream>
#include "CMatrix.h"

using namespace std;

int main() {
	CMatrix<int> m;
	m.Read(2,2);

	(m * m).Print();


}

