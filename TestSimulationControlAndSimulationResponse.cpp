/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestSimulationControlAndSimulationResponse.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 17:44
 */

#include "TestSimulationControlAndSimulationResponse.h"
#include "Simulator.h"
#include "Model.h"
#include "SimulationControl.h"
#include "SimulationResponse.h"
#include <iostream>

TestSimulationControlAndSimulationResponse::TestSimulationControlAndSimulationResponse() {
}


int TestSimulationControlAndSimulationResponse::main(int argc, char** argv){
    Simulator* simulator = new Simulator();
    TraceManager* tm = simulator->tracer();
    this->setDefaultTraceHandlers(tm);
    tm->setTraceLevel(Util::TraceLevel::mostDetailed);
    
    Model* model = new Model(simulator);
    model->show();
    
    std::cout << "NumRepl antes: " << model->infos()->getNumberOfReplications() << std::endl;
    model->infos()->setNumberOfReplications(10);
    std::cout << "NumRepl depois: " << model->infos()->getNumberOfReplications() << std::endl;
    SimulationControl* control = model->controls()->front();
    std::cout << control->getName() << " antes: " << control->getValue() << std::endl;
    control->setValue(20);
    std::cout << control->getName() << " depois: " << control->getValue() << std::endl;
    std::cout << "NumRepl depois: " << model->infos()->getNumberOfReplications() << std::endl;
    return 0;
}