#include <iostream>
#include <vector>
#include <fstream>

#include "matrix.h"

int main (int argc, char* argv[]) {
	int y= 0;

	std::vector<int> init_1 = { -2, 5, 1, 0, 8, -7, 9, -4, -3 };
	std::vector<int> init_2 = { 3, -4, 6, -5, 2, -1, 8, 9, 0 };
	std::vector<int> init_3 = { 1, 2, 3, 4 };
	
	CMatrix<int> m_1(3, 3, init_1);	
	CMatrix<int> m_2(3, 3, init_2);
	CMatrix<int> m_3(2, 2, init_3);

	m_1.Print();
	m_2.Print();
	m_3.Print();
	
	m_3 = m_1 + m_2;
	m_3.Print();

	m_3 = m_1 - m_2;
	m_3.Print();

	m_3 = m_1 * m_2;
	m_3.Print();

	m_3 = m_3 * 4;
	m_3.Print();

	return 0;
}
