#include "ClickableManager.h"

namespace pg{
ClickableManager::ClickableManager()
{
    //ctor
}

ClickableManager::~ClickableManager()
{
    //dtor
}
void ClickableManager::notify(MouseEvent e){
     pg::Coord c=e.coord;

    if(e.click==e.LEFT_DOWN){
        this->_downClick=c;

    }
    if(e.click==e.LEFT_UP){
        for(auto x: this->listeners)
        {
            //TODO :Clickable Manager everything
            HitBox* b;//=x->getHitBox();
            if(b->pointBelongsTo(c)&& b->pointBelongsTo(_downClick)){
                x->notify(0);
            }

        }
    }


}
}
