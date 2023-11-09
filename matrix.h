#ifndef __MATRIX_H_INCLUDED__
#define __MATRIX_H_INCLUDED__

#include <vector>

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
		int GetOrder();

		//Add support for std::cout <<, ^
		CMatrix<T> operator+(CMatrix<T> const&);
		CMatrix<T> operator-(CMatrix<T> const&);
		CMatrix<T> operator*(CMatrix<T> const&);
		CMatrix<T> operator*(int const&);
	
		int Height;
		int Width;
	private:
		//vector of rows and columns, set by the GetElement(x, y) function
		std::vector<std::vector<T> > rows;
		std::vector<std::vector<T> > columns;
};

//change into two seperate functions:
//	first sizes the vector
//	second takes either a const int parameter to define:
//		0) NULL (ZERO MATRIX)
//		1) IDENTITY
template <typename T>
CMatrix<T>::CMatrix(int width_t, int height_t, std::vector<T> initialise_vector_t) {
	Height = height_t;
	Width = width_t;
	
	int t = 0;

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

template <typename T>
void CMatrix<T>::InitialiseElements(std::vector<T> init_t) {
	int current = 0;
	int p = 0;

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
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
	for(int i = 0; i < Height; i++) {
		for(int j = 0; j < Width; j++) {
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

	//refactor into matrix member-function
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
CMatrix<T> CMatrix<T>::operator*(CMatrix<T> const& other) {
	/*std::vector<T> temp;
	temp.resize(Width * Height);
	std::fill(temp.begin(), temp.end(), 0);
	CMatrix<T> m_t(Width, Height, temp);

	//refactor into matrix member-function
	if(other.rows.size() || this->columns.size()) {
		std::cout << "non-matching order";
		return m_t;
	}
	*/

	std::vector<T> temp;
	temp.resize(this->columns.size() * other.rows.size());
	std::fill(temp.begin(), temp.end(), 0);
	CMatrix<T> m_t2(other.columns.size(), this->rows.size(), temp);

	int p = 0;
	std::cout << m_t2.Width << " " << m_t2.Height << std::endl;

	for(int i = 0; i < m_t2.Width; i++) {
		for (int j = 0; j < m_t2.Height; j++) {
			int fill = 0;
			for (int k = 0; k < Width; k++) {
				std::cout << "X: " << i << "Y: " << j << "K: " << k << std::endl;
				fill += this->rows[j][k] * other.columns[i][k];
			}

			m_t2.SetElement(i, j, fill);
			fill = 0;
		}
	}

	std::cout << "matrix multiplication\n\n";
	return m_t2;
}

template <typename T>
CMatrix<T> CMatrix<T>::operator*(int const& scalar) {
	for (int i = 0; i < Width; i++) {
		for (int j = 0; j < Height; j++) {
			int current = GetElement(j, i) * scalar;
			SetElement(j, i, current);
		}
	}

	return *this;
}
template <typename T>
int CMatrix<T>::GetOrder() {
	return this->Width * this->Height;
}

#endif
