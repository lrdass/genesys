/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Schedule.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:16
 */

#ifndef SCHEDULE_H
#define SCHEDULE_H

class Model;

class Schedule {
public:
    Schedule(Model* model);
    virtual ~Schedule() = default;
private:

};

#endif /* SCHEDULE_H */

