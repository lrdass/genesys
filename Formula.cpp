/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Formula.cpp
 * Author: rlcancian
 * 
 * Created on 20 de Junho de 2019, 00:56
 */

#include "Formula.h"
#include <iostream>
#include "ElementManager.h"
#include "Model.h"
#include "Traits.h"

Formula::Formula(Model* model) : ModelElement(model, Util::TypeOf<Formula>()) {
    //_elements = elements;
    _myPrivateParser = new Traits<Parser_if>::Implementation(_parentModel);
}

void Formula::setFormulaExpression(std::string _formulaExpression) {
    this->_formulaExpression = _formulaExpression;
}

std::string Formula::getFormulaExpression() const {
    return _formulaExpression;
}

double Formula::getValue() const {
    double value = -99.9;//_myPrivateParser->parse(_formulaExpression);
    return value;
}


std::string Formula::show() {
    return ModelElement::show()+
	    ",formulaExpression=\""+this->_formulaExpression+"\"";
}

PluginInformation* Formula::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Formula>(), &Formula::LoadInstance); return info;
}

ModelElement* Formula::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Formula* newElement = new Formula(model);
    try {
	newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

bool Formula::_loadInstance(std::map<std::string, std::string>* fields) {
    return ModelElement::_loadInstance(fields);
}

std::map<std::string, std::string>* Formula::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelElement::_saveInstance();
    //fields->emplace("...", std::to_string(this->_...));
    return fields;
}

bool Formula::_check(std::string* errorMessage) {
    std::string errorMsg="";
    bool res  = _parentModel->checkExpression(this->_formulaExpression,"formula expression", &errorMsg);
    return res;
}
