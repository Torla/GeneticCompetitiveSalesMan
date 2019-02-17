//
// Created by munfo on 10/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_MATRIX_H
#define GENETICCOMPETITIVESALESMAN_MATRIX_H


#include <vector>
#include <stdexcept>

template <typename T>
class Matrix {
private:
	unsigned int dim;
	std::vector<T> mat;
public:
	explicit Matrix(unsigned int dim)
			: dim(dim){
		mat.resize(dim*dim);
	}

	T& operator()(unsigned int x, unsigned int y){
		return mat.at(x*dim+y);
	}
	const T& operator()(unsigned int x, unsigned int y) const {
		return mat.at(x*dim+y);
	}

	unsigned int size() const { return dim;}

};


#endif //GENETICCOMPETITIVESALESMAN_MATRIX_H
