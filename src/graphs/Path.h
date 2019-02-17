//
// Created by munfo on 08/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_PATH_H
#define GENETICCOMPETITIVESALESMAN_PATH_H


#include <vector>
#include <stdexcept>

class Path: public std::vector<unsigned int>{

public:
	explicit Path(unsigned int length):std::vector<unsigned int>(){
		this->assign(length,0);
	};

	unsigned int& operator[](unsigned int i){
		return this->at(i);
	}

	std::vector<unsigned int> getLinkRepresentation(){
		std::vector<unsigned int> ret(this->size());
		for(register unsigned int i=0;i<this->size();i++){
			ret[this->at(i)]=this->at((i+1)%this->size());
		}
		return ret;
	}

};


#endif //GENETICCOMPETITIVESALESMAN_PATH_H
