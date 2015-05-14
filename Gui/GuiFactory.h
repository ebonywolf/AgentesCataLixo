#ifndef GUIFACTORY_H
#define GUIFACTORY_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <ProjGaia/Tools/Polygon.h>
#include "GuiWorld.h"
#include "Robot.h"
#include <ProjGaia/SFML/DrawableObject.h>
#include <ProjGaia/SFML/DrawableSprite.h>
#include <list>

#define SIZE_X 50
#define SIZE_Y 50
#define WINDOW_SIZE pg::Coord(800,600)
#define ROBOT_PATH "Img/Walle.png"
class GuiFactory
{
    public:

        GuiFactory();

//        static createWorld();
        static pg::DrawableSprite* createRobotSprite();
        static pg::DrawableSprite* createTrashSprite(){return 0;};
         static pg::DrawableSprite* createCanSprite(){return 0;};
        static std::list<sf::Drawable*> getGroundTextures();
        static pg::Polygon createRect(pg::Coord dimension, pg::Coord position);
        virtual ~GuiFactory();
    protected:
        static sf::Texture* robot;
    private:
};

#endif // GUIFACTORY_H
