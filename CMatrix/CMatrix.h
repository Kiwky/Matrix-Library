#include <iostream>
#include <cmath>
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

	/* Calculare determinat matrice. (Chio) */
	T Determinant();

	/* Suprascriere operator '+'. Returneaza suma a doua matrice. */
	CMatrix operator+(const CMatrix &matrix);

	/* Suprascriere operator '+'. Returneaza matricea unde fiecare elemente este incrementat cu '_value'. */
	CMatrix operator+(T _value);

	/* Suprascriere operator '-'. Returneaza diferenta a doua matrice. */
	CMatrix operator-(const CMatrix &matrix);

	/* Suprascriere operator '-'. Returneaza matricea unde fiecare elemente este decrementat cu '_value'. */
	CMatrix operator-(T _value);

	// INCOMPLET
	/* Suprascriere operator '*'. Returneaza produsul a doua matrice. */
	CMatrix operator*(const CMatrix &matrix);
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
T CMatrix<T>::Determinant() {
	// Verificare matrice 1x1.
	// ???????????????????????

	// Matricea nu exista, nu este patratica sau nu are elemente.
	if(Cols() <= 0 || Lines() <= 0 || Lines() != Cols()) { return 0; }

	// Matrice 2 x 2.
	if(Lines() == 2 && Cols() == 2) {
		return data[0][0] * data[1][1] - data[0][1] * data[1][0];
	}

	// Calculare determinant (Chio).
	CMatrix tempMatrix, auxMatrix;
	int beforeMatrix = 1, size = Lines();

	tempMatrix.data = this->data;

	while(size > 2) {
		beforeMatrix *= pow(tempMatrix.data[0][0], size - 2);

		auxMatrix.data.clear();
		for(int i = 1; i < size; i++) {
			vector<T> lineData;
			lineData.reserve(Cols());

			for(int j = 1; j < size; j++) {
				int res = (tempMatrix.data[0][0] * tempMatrix.data[i][j] - tempMatrix.data[0][j] * tempMatrix.data[i][0]);
				lineData.emplace_back(res);
			}

			auxMatrix.data.emplace_back(lineData);
		}

		tempMatrix.data.clear();
		tempMatrix = auxMatrix;

		size--;
	}

	return ((tempMatrix.data[0][0] * tempMatrix.data[1][1] - tempMatrix.data[0][1] * tempMatrix.data[1][0]) / beforeMatrix);
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
CMatrix<T> CMatrix<T>::operator+(T _value) {
	CMatrix result(Lines(), Cols(), 0);

	for(uint i = 0; i < Lines(); i++) {
		for(uint j = 0; j < Cols(); j++) {
			result.data[i][j] = data[i][j] + _value;
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

template<typename T>
CMatrix<T> CMatrix<T>::operator-(T _value) {
	CMatrix result(Lines(), Cols(), 0);

	for(uint i = 0; i < Lines(); i++) {
		for(uint j = 0; j < Cols(); j++) {
			result.data[i][j] = data[i][j] - _value;
		}
	}

	return result;
}

template<typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix &matrix) {
	return CMatrix();
}
