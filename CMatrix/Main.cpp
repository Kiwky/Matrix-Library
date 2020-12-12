#include <iostream>
#include "CMatrix.h"

using namespace std;

int main() {
	CMatrix<int> m(3, 3, 2);
	CMatrix<int> n(3, 3, 5);
	(m - 10).Print();
}
