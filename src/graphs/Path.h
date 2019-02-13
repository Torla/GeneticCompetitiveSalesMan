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


};


#endif //GENETICCOMPETITIVESALESMAN_PATH_H
