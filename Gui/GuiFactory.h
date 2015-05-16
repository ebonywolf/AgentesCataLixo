#ifndef GUIFACTORY_H
#define GUIFACTORY_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <ProjGaia/Tools/Polygon.h>
#include "GuiWorld.h"
#include "Robot.h"
#include <ProjGaia/SFML/DrawableObject.h>
#include <ProjGaia/SFML/DrawableSprite.h>
#include "TrashTypes.h"
#include <unordered_map>
#include <list>

#define SIZE_X 50
#define SIZE_Y 50
#define WINDOW_SIZE pg::Coord(800,600)
#define ROBOT_PATH "Img/Walle.png"
#define FLOOR_PATH "Img/Floor.jpg"
#define TRASH_BIN_PATH "Img/Lixeiras.png"
class GuiFactory
{
	public:

		GuiFactory() = delete;

//        static createWorld();
		static pg::DrawableSprite* createRobotSprite();
		static pg::DrawableSprite* createTrashSprite ( TrashTypes );
		static pg::DrawableSprite* createCanSprite ( TrashTypes );
		static pg::DrawableSprite* createGroundTexture();
		static pg::Polygon createRect ( pg::Coord dimension, pg::Coord position );
		virtual ~GuiFactory();

		static std::map<TrashTypes, sf::Color> colorCodes;
		static void setColorCodes();
		static pg::Renderer* debugDraw;
	protected:

	    static std::map<TrashTypes,sf::Texture*> trashBin;
		static sf::Texture* robot;
		static sf::Texture* floor;
		static std::map<TrashTypes,pg::Coord> trashBinPos;


	private:
};

#endif // GUIFACTORY_H
