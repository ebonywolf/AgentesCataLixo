#ifndef ROBOTAI_H
#define ROBOTAI_H

#include "Robot.h"

class RobotAI : public Robot {
  public:
    RobotAI();
    void turn();
  private:
    int vez;
    pg::Coord lixeiraDestino;
    pg::Coord last;
    bool saiu;
};


#endif
