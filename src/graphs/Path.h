//
// Created by munfo on 08/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_PATH_H
#define GENETICCOMPETITIVESALESMAN_PATH_H


#include <vector>
#include <stdexcept>

class Path: private std::vector<unsigned int>{

public:
	explicit Path(unsigned int length):std::vector<unsigned int>(){
		this->assign(length,0);
	};


	std::vector<unsigned int> getLinkRepresentation(){
		std::vector<unsigned int> ret(this->size());
		for(register unsigned int i=0;i<this->size();i++){
			ret[this->at(i)]=this->at((i+1)%this->size());
		}
		return ret;
	}

	unsigned int get(unsigned int i) const {
		return this->at(i);
	}

unsigned int &operator[](size_type __n) {
		return vector::operator[](__n);
	}

public:

	void clear(){
		vector::clear();
	}

	unsigned int size() const {
		return vector::size();
	}

	iterator begin() {
		return vector::begin();
	}

	iterator end() {
		return vector::end();
	}

void push_back(const value_type &__x) {
		vector::push_back(__x);
	}

};


#endif //GENETICCOMPETITIVESALESMAN_PATH_H
