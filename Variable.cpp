/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 4 de Setembro de 2018, 18:28
 */

#include "Variable.h"

Variable::Variable() : ModelElement(Util::TypeOf<Variable>()) {
}

Variable::Variable(std::string name) : ModelElement(Util::TypeOf<Variable>()) {
    _name = name;
}

Variable::Variable(const Variable& orig) : ModelElement(orig) {
}

Variable::~Variable() {
}

std::string Variable::show() {
    return ModelElement::show(); // @TODO: include values
}

double Variable::getValue() {
    return getValue("");
}

double Variable::getValue(std::string index) {
    std::map<std::string, double>::iterator it = _values->find(index);
    if (it == _values->end()) {
	return 0.0; // index does not exist. Assuming sparse matrix, it's zero. 
    } else {
	return it->second;
    }
}

void Variable::setValue(double value) {
    setValue("", value);
}

void Variable::setValue(std::string index, double value) {
    std::map<std::string, double>::iterator it = _values->find(index);
    if (it == _values->end()) {
	// index does not exist. Create it.
	_values->insert(std::pair<std::string, double>(index, value));
    } else {
	it->second = value;
    }
}

bool Variable::_loadInstance(std::map<std::string, std::string>* fields) {
    return ModelElement::_loadInstance(fields);
}

std::map<std::string, std::string>* Variable::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Variable>());
    fields->emplace("numCols" , std::to_string(this->_numCols));
    fields->emplace("numRows" , std::to_string(this->_numRows));
    unsigned int i=0;
    for (std::map<std::string, double>::iterator it = this->_values->begin(); it != _values->end(); it++) {
	fields->emplace("pos"+std::to_string(i) , (*it).first);
	fields->emplace("value"+std::to_string(i) , std::to_string((*it).second));
	i++;
    }
    return fields;
}

bool Variable::_check(std::string* errorMessage) {
    return true;
}
