#include <iostream>
#include <vector>
#include <fstream>

#include "matrix.h"

int main (int argc, char* argv[]) {
	std::vector<int> init_1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	std::vector<int> init_2 = { 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::vector<int> init_3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

	CMatrix<int> m_1(4, 4, init_1);
	CMatrix<int> m_2(4, 4, init_2);
	CMatrix<int> m_4(3, 3, init_3);
	CMatrix<int> m_3(4, 4, init_1);

	m_3 = m_1 + m_2;

	m_1.Print();
	m_2.Print();
	m_3.Print();

	m_3 = m_1 + m_1;
	m_3.Print();

	m_3 = m_1 + m_4;
	m_3.Print();

	m_3 = m_1 - m_2;
	m_3.Print();

	return 0;
}
