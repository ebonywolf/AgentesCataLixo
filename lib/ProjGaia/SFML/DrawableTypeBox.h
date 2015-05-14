#ifndef DRAWABLETYPEBOX_H
#define DRAWABLETYPEBOX_H


#include <ProjGaia/Tools/TypeBox.h>
#include "DrawableSprite.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class DrawableTypeBox:public pg::DrawableSprite,public TypeBox
{
    public:

        DrawableTypeBox(sf::Font *font,pg::Coord coord);

        virtual ~DrawableTypeBox();

        void update(void*);
        void draw ( sf::RenderTarget&, sf::RenderStates )const ;

    protected:
        sf::Text text;
    private:
};

#endif // DRAWABLETYPEBOX_H
