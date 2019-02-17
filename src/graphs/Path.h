//
// Created by munfo on 08/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_PATH_H
#define GENETICCOMPETITIVESALESMAN_PATH_H


#include <vector>
#include <stdexcept>
#include <iostream>

class Path: private std::vector<unsigned int>{

	mutable std::vector<unsigned int> linkRep;
	mutable bool linkRepValid;

public:
	explicit Path(unsigned int length):std::vector<unsigned int>(),linkRepValid(false),linkRep(length){
		this->assign(length,0);
	};


	std::vector<unsigned int> getLinkRepresentation() const{
		if(linkRepValid){
			return linkRep;
		}
		for(register unsigned int i=0;i<this->size();i++){
			linkRep[this->at(i)]=this->at((i+1)%this->size());
		}
		linkRepValid = true;
		return linkRep;
	}

	unsigned int get(unsigned int i) const {
		return this->at(i);
	}

	unsigned int &operator[](size_type __n) {
		linkRepValid= false;
		return vector::operator[](__n);
	}

public:

	void clear(){
		linkRepValid= false;
		vector::clear();
	}

	unsigned int size() const {
		return vector::size();
	}

	iterator begin() {
		linkRepValid= false;
		return vector::begin();
	}

	iterator end() {
		linkRepValid= false;
		return vector::end();
	}

	void push_back(const value_type &__x) {
		vector::push_back(__x);
	}

};


#endif //GENETICCOMPETITIVESALESMAN_PATH_H
