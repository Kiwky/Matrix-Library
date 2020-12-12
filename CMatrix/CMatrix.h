#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using uint = unsigned int;

template <typename T>
class CMatrix {

public:
	vector<vector<T>> data;

public:
	/* Constructor 1 */
	CMatrix() {}

	/* Constructor 2 - Umple matrice cu o valoare. */
	CMatrix(uint _lines, uint _cols, T _default);

	/* Returneaza numarul de linii din matrice. (0 - Matricea este goala) */
	int Lines() const;

	/* Returneaza numarul de coloane din matrice. (0 - Matricea este goala) */
	int Cols() const;

	/* Citeste o matrice. Returneaza 0 - eroare | 1 - succes. */
	int Read(uint _lines, uint _cols);

	/* Afisare matrice. */
	void Print();

	/* Suprascriere operator '+'. Returneaza suma a doua matrice. */
	CMatrix operator+(const CMatrix &matrix);

	/* Suprascriere operator '-'. Returneaza diferenta a doua matrice. */
	CMatrix operator-(const CMatrix &matrix);
};

template<typename T>
CMatrix<T>::CMatrix(uint _lines, uint _cols, T _default) {
	vector<T> lineData;
	lineData.reserve(_cols);

	for(uint i = 0; i < _lines; i++) {
		// Se curata elementele liniei inainte de a incepe sa le citim.
		lineData.clear();

		for(uint j = 0; j < _cols; j++) {
			lineData.emplace_back(_default);
		}

		// Adauga linia citita in matrice.
		data.emplace_back(lineData);
	}
}

template<typename T>
int CMatrix<T>::Lines() const {
	if(data.empty()) return 0;
	return data.size();
}

template<typename T>
int CMatrix<T>::Cols() const {
	if(data.empty()) return 0;
	return data[0].size();
}

template<typename T>
int CMatrix<T>::Read(uint _lines, uint _cols) {
	if(_lines <= 0 || _cols <= 0 || _lines >= INT_MAX || _cols >= INT_MAX) {
		//throw exception("Range error");
		return 0;
	}

	vector<T> lineData;
	lineData.reserve(_cols);

	for(uint i = 0; i < _lines; i++) {
		// Se curata elementele liniei inainte de a incepe sa le citim.
		lineData.clear();

		for(uint j = 0; j < _cols; j++) {
			T value;
			cin >> value;
			lineData.emplace_back(value);
		}

		// Adauga linia citita in matrice.
		data.emplace_back(lineData);
	}

	return 1;
}

template<typename T>
void CMatrix<T>::Print() {
	int lines = Lines();
	int cols = Cols();

	if(lines <= 0 || cols <= 0) return;

	for(uint i = 0; i < lines; i++) {
		for(uint j = 0; j < cols; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

template<typename T>
CMatrix<T> CMatrix<T>::operator+(const CMatrix &matrix) {
	if(matrix.Lines() != Lines() || matrix.Cols() != Cols()) {
		return CMatrix();
	}

	CMatrix result(Lines(), Cols(), 0);

	for(uint i = 0; i < Lines(); i++) {
		for(uint j = 0; j < Cols(); j++) {
			result.data[i][j] = data[i][j] + matrix.data[i][j];
		}
	}

	return result;
}

template<typename T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix &matrix) {
	if(matrix.Lines() != Lines() || matrix.Cols() != Cols()) {
		return CMatrix();
	}

	CMatrix result(Lines(), Cols(), 0);

	for(uint i = 0; i < Lines(); i++) {
		for(uint j = 0; j < Cols(); j++) {
			result.data[i][j] = data[i][j] - matrix.data[i][j];
		}
	}

	return result;
}