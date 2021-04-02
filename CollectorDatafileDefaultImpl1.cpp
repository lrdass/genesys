/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileDefaultImpl11.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 1 de Agosto de 2018, 20:58
 */

#include "CollectorDatafileDefaultImpl1.h"

CollectorDatafileDefaultImpl1::CollectorDatafileDefaultImpl1() {
    wasFileSorted = false;
    _filename = "datafile.dat";

    _datafile = new DataFileArray(_filename.c_str());

}

void CollectorDatafileDefaultImpl1::clear() {
    _datafile->clear();
    
    this->_numElements = 0;
    if(_clearHandler != nullptr){
        _clearHandler();
    }
    
}

void CollectorDatafileDefaultImpl1::addValue(double value) { 
    
    wasFileSorted = false;
    if(_sortedFile != nullptr)
        _sortedFile->clear();
    
    _datafile->write(value);
    
    this->_lastValue = value;
    this->_numElements +=1;
    
    if(_addValueHandler != nullptr){
        _addValueHandler(value);
    }
}


double CollectorDatafileDefaultImpl1::getLastValue() {
    return this->_lastValue;
}

unsigned long CollectorDatafileDefaultImpl1::numElements() {
	return this->_numElements;
}

double CollectorDatafileDefaultImpl1::getValue(unsigned int num) {
    return _datafile->read(num);
}

double CollectorDatafileDefaultImpl1::getNextValue() {
	return 0.0; // \todo:
}

void CollectorDatafileDefaultImpl1::seekFirstValue() {
}

std::string CollectorDatafileDefaultImpl1::getDataFilename() {
	return _filename;
}

void CollectorDatafileDefaultImpl1::setDataFilename(std::string filename) {
	_filename = filename;
}

void CollectorDatafileDefaultImpl1::setAddValueHandler(CollectorAddValueHandler addValueHandler) {
    _addValueHandler = addValueHandler;
}

void CollectorDatafileDefaultImpl1::setClearHandler(CollectorClearHandler clearHandler) {
    _clearHandler = clearHandler;
}


double CollectorDatafileDefaultImpl1::getValueOrdered(unsigned int num){
    if(wasFileSorted){
        return _sortedFile->read(num);
    }
    else{
        _datafile->sortFile();
        return _sortedFile->read(num);
    }
}