#include "Control.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
Control::Control()
{
    //ctor
}

Control::~Control()
{
    //dtor
}
void Control::notify(pg::KeyBoardEvent e){
    if(e.type==e.DOWN){
        switch (e.key)
        {
            case sf::Keyboard::S: {moveUp();
                break;
            }
             case sf::Keyboard::W: {moveDown();
                break;
            }
             case sf::Keyboard::A: {moveLeft();
                break;
            }
             case sf::Keyboard::D: {moveRight();
                break;
            }
             case sf::Keyboard::F: {interactThrash();
                break;
            }
            default:
                break;
        }

    }

}
