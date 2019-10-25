/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectionManager.h
 * Author: rlcancian
 *
 * Created on 1 de Julho de 2019, 18:39
 */

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <utility>
#include "List.h"

class ModelComponent;

typedef std::pair<ModelComponent*, unsigned int> Connection;

class ConnectionManager {
public:
    ConnectionManager();
    virtual ~ConnectionManager() = default;
public:
    unsigned int size();
    ModelComponent* front(); /*!< DEPRECTED. Use  frontConnection instead */    
    ModelComponent* getAtRank(unsigned int rank); /*!< DEPRECTED. Use  getConnectionAtRank instead */
    Connection* frontConnection();
    Connection* getConnectionAtRank(unsigned int rank);
    void insert(ModelComponent* component, unsigned int inputNumber = 0);
    std::list<Connection*>* list() const;
private:
    List<Connection*>* _nextConnections = new List<Connection*>();
};

#endif /* CONNECTIONMANAGER_H */

