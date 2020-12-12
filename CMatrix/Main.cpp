#include <iostream>
#include "CMatrix.h"

using namespace std;

int main() {
	CMatrix<int> n;
	n.Read(3, 3);
	cout << n.Determinant();
}
