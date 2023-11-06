#ifndef __MATRIX_H_INCLUDED__
#define __MATRIX_H_INCLUDED__

#include <vector>

//template <class T> class Matrix;
//template <typename T> Matrix<T> operator+(Matrix<T> const&, Matrix<T> const&);

template <class T>
class CMatrix {
	public:
		//Initialise with width, height and matrix elements
		CMatrix<T>(int, int, std::vector<T>);

		//Destroy Mamtrix
		~CMatrix<T>() = default;

		void InitialiseElements(std::vector<T>);

		//Return given element (x, y)
		T GetElement(int, int);
		
		//Set elements, used by constructor and user
		void SetElement(int, int, T);

		void Print();

		CMatrix<T> operator+(CMatrix<T> const&);
		CMatrix<T> operator-(CMatrix<T> const&);
		CMatrix<T> operator*(CMatrix<T> const&);
	
		int Height;
		int Width;
	private:
		//vector of rows and columns, set by the GetElement(x, y) function
		std::vector<std::vector<T> > rows;
		std::vector<std::vector<T> > columns;
};

template <typename T>
CMatrix<T>::CMatrix(int width_t, int height_t, std::vector<T> initialise_vector_t) {
	Height = height_t;
	Width = width_t;

	rows.resize(height_t);
	for(int i = 0; i < Height; i++) {
		rows[i].resize(Width);
	}

	columns.resize(width_t);
	for(int i = 0; i < Width; i++) {
		columns[i].resize(Height);
	}

	InitialiseElements(initialise_vector_t);
}

//ROWS ------->
//COLUMN
//	|
//	|
//	|
//     \/

template <typename T>
void CMatrix<T>::InitialiseElements(std::vector<T> init_t) {
	int current = 0;
	int pox;

	for (int i = 0; i < Width; i++) {
		for (int j = 0; j < Height; j++) {
			SetElement(j, i, init_t[current]);
			current++;
		}
	}

	return;
}

template <typename T>
void CMatrix<T>::SetElement(int x, int y, T t) {
	columns[x][y] = t;
	rows[y][x] = t;
	return;
}

template <typename T>
T CMatrix<T>::GetElement(int x, int y) {
	T t = rows[y][x];

	return t;
}

template <typename T>
void CMatrix<T>::Print() {
	for(int i = 0; i < Width; i++) {
		for(int j = 0; j < Height; j++) {
			std::cout << GetElement(j, i) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

}
template <class T>
CMatrix<T> CMatrix<T>::operator+ (const CMatrix<T>& other) {	
	std::vector<T> temp;
	temp.resize(Width * Height);
	std::fill(temp.begin(), temp.end(), 0);

	CMatrix<T> m_t(Width, Height, temp);

	if(other.Width != this->Width || other.Height != this->Height) {
		std::cout << "non-matching dimensions";
		return m_t;
	}

	for (int i = 0; i < other.Width; i++) {
		for (int j = 0; j < other.Height; j++) {
			int val = other.rows[j][i] + this->rows[j][i];

			m_t.SetElement(i, j, val);
		}
	}
	
	std::cout << "matrix addition" << std::endl;
	return m_t;
}

template <typename T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix<T>& other) {
	//refactor into matrix member-function
	std::vector<T> temp;
	temp.resize(Width * Height);
	std::fill(temp.begin(), temp.end(), 0);
	CMatrix<T> m_t(Width, Height, temp);

	//refactor into matrix member-fection
	if(other.Width != this->Width || other.Height != this->Height) {
		std::cout << "non-matching dimensions";
		return m_t;
	}

	for (int i = 0; i < other.Width; i++) {
		for (int j = 0; j < other.Height; j++) {
			int val = this->rows[j][i] - other.rows[j][i];

			m_t.SetElement(i, j, val);
		}
	}
	
	std::cout << "matrix addition" << std::endl;
	return m_t;
}

template <typename T>
CMatrix<T> operator*(CMatrix<T> const& m1, CMatrix<T> const& m2) {
	std::vector<T> init_3 = { 1 };
	CMatrix<T> m3(1, 1, init_3);

	std::cout << "matrix multiplication";
	return m3;
}

#endif
