#include "RobotAI.h"
#include "Trash.h"
RobotAI::RobotAI() {
  vez = 0;
  last = getPosition();
  saiu = false;
}

void RobotAI::turn() {
  bool aesquerda;
  bool adireita;
  bool notopo;
  bool embaixo;


  if (vez == 0) {
    if (this->getPosition().x == 0)
      aesquerda = true;
      else
      aesquerda = false;

    if (this->getPosition().y == 0)
      embaixo = true;
      else
      embaixo = false;

    if (this->getPosition().x == this->getMapWidth())
      adireita = true;
      else
      adireita = false;

    if (this->getPosition().y == this->getMapHeight())
      notopo = true;
      else
      notopo = false;

      vez++;
  }


  /*if (!(scan()) && !(getCarryingTrash()) && !saiu) {                           //Se nenhum lixo foi encontrado no espaço atual e não estiver carregando nada.
    if (!aesquerda) {                                                  //Se o robô não foi ao limite esquerdo do mapa recentemente.
      if (this->getPosition().x > 0) {                            //Se ele não estiver no limite esquerdo do mapa agora.
        this->moveLeft();
      } else {
        aesquerda = true;
        adireita = false;
        if(!embaixo) {                                                 //Se o robô não esteve no topo do mapa recentemente.
          if (this->getPosition().y > 0) {                        //Se o robô não está no topo do mapa agora.
            this->moveDown();
          } else {                                                    //Se o robô estiver a esquerda e visitou o topo do mapa recentemente.
            embaixo = true;
            notopo = false;
            this->moveRight();
          }
        }
      }
    } else {                                                           //Se o robô esteve à esquerda recentemente.
      if (this->getPosition().x < (this->getMapWidth() )) {             //Se não estiver à direita agora.
        this->moveRight();
      } else {                                                         //Se o robô esteve à esquerda recentemente e agora chegou à direita.
        adireita = true;
        aesquerda = false;
        if (!notopo) {                                                //Se o robô não esteve no limite inferior do mapa recentemente.
          if (this->getPosition().y < (this->getMapHeight() )) {        //Se o robô não estiver no limite inferior do mapa agora.
            this->moveUp();
          } else {
            notopo = true;
            embaixo = false;
            this->moveDown();
          }
        }
      }
    }
  }*/

  if(!scan() && !(getCarryingTrash())) {
    if (!aesquerda) {
        if(this->getPosition().x == 0) {
            aesquerda = true;
            adireita = false;
        } else {
            this->moveLeft();
        }
    } else if (!embaixo) {
        if(this->getPosition().y == 0) {
            embaixo = true;
            notopo = false;
        } else {
            this->moveDown();
        }
    } else if (!adireita) {
        if(this->getPosition().x == this->getMapWidth()) {
            adireita = true;
            aesquerda = false;
        } else {
            this->moveRight();
        }
    } else if (!notopo) {
        if(this->getPosition().y == this->getMapHeight()) {
            notopo = true;
            embaixo = false;
        } else {
            this->moveUp();
        }
    }
  }


  if (scan() && !(getCarryingTrash())) {                               //Agora, se for encontrado algum lixo no espaço atual e não estiver carregando nada.
    this->interactThrash();
    Trash * scanned = scan();
    TrashTypes scannedType = scanned->type;
    lixeiraDestino = getTrashCan(scannedType);
    last = getPosition();
    saiu = true;
  }


  if (!scan() && (getCarryingTrash() != 0)) {                           //Se nenhum lixo foi encontrado no espaço atual mas já estiver carregando alguma coisa.
    if ((lixeiraDestino.x - getPosition().x) < 0) {
      this->moveLeft();
    } else if ((lixeiraDestino.x - getPosition().x) > 0) {
      this->moveRight();
    } else if ((lixeiraDestino.y - getPosition().y) < 0) {
      this->moveDown();
    } else if ((lixeiraDestino.y - getPosition().y) > 0) {
      this->moveUp();
    } else if ((lixeiraDestino.x == getPosition().x) && (lixeiraDestino.y == getPosition().y)) {
      this->interactThrash();
    }
  }

  if (scan() && (getCarryingTrash() != 0)) {                          //Se for encontrado um lixo enquanto estiver carregando outro.

    TrashTypes carrying , scanned;
    carrying = getCarryingTrash()->type;
    scanned = scan()->type;
    if (scanned > carrying) {
      lixeiraDestino = getTrashCan(scanned);
      this->interactThrash();
    } else if ((lixeiraDestino.x - getPosition().x) < 0) {
      this->moveLeft();
    } else if ((lixeiraDestino.x - getPosition().x) > 0) {
      this->moveRight();
    } else if ((lixeiraDestino.y - getPosition().y) < 0) {
      this->moveDown();
    } else if ((lixeiraDestino.y - getPosition().y) > 0) {
      this->moveUp();
    }

  }

  if ((getCarryingTrash() != 0) && saiu) {
    if ((last.x - getPosition().x) < 0) {
      this->moveLeft();
    } else if ((last.x - getPosition().x) > 0) {
      this->moveRight();
    } else if ((last.y - getPosition().y) < 0) {
      this->moveUp();
    } else if ((last.y - getPosition().y) > 0) {
      this->moveDown();
    } else if ((last.x == getPosition().x) && (last.y == getPosition().y)) {
      saiu = false;
    }
  }






}
