/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ComponentManager.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 28 de Maio de 2019, 10:41
 */

#include "ComponentManager.h"
#include "List.h"

ComponentManager::ComponentManager(Model* model) {
    _model = model;
    _components = new List<ModelComponent*>();
    _components->setSortFunc([](const ModelComponent* a, const ModelComponent * b) {
	return a->getId() < b->getId(); /// Components are sorted by ID
    });
}


bool ComponentManager::insert(ModelComponent* comp) {
    if (_components->find(comp) == _components->list()->end()) {
	_components->insert(comp);
	return true;
    }
    return false;
}

void ComponentManager::remove(ModelComponent* comp) {
    _components->remove(comp);
}

void ComponentManager::clear() {
    this->_components->clear();
}

//ModelComponent* ComponentManager::getComponent(Util::identification id) {
//}

//ModelComponent* ComponentManager::getComponent(std::string name) {
//}

unsigned int ComponentManager::getNumberOfComponents() {
    return _components->size();
}

std::list<ModelComponent*>::iterator ComponentManager::begin() {
    return _components->list()->begin();
}

std::list<ModelComponent*>::iterator ComponentManager::end() {
    return _components->list()->end();
}