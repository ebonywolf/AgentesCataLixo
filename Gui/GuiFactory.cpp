#include "GuiFactory.h"
#include <ProjGaia/SFML/TexturedSprite.h>
#include <ProjGaia/SFML/ColoredShape.h>
#include <ProjGaia/SFML/Renderer.h>
using namespace pg;


sf::Texture* GuiFactory::robot = 0;
sf::Texture* GuiFactory::floor = 0;
Renderer* GuiFactory::debugDraw=0;
std::map<TrashTypes, sf::Color> GuiFactory::colorCodes = std::map<TrashTypes, sf::Color>();
std::map<TrashTypes,sf::Texture*> GuiFactory::trashBin =  std::map<TrashTypes,sf::Texture*>();
std::map<TrashTypes,pg::Coord> GuiFactory::trashBinPos= std::map<TrashTypes,pg::Coord>();

GuiFactory::~GuiFactory()
{
	//dtor
}
void GuiFactory::setColorCodes ()
{
	colorCodes[TrashTypes::ORGANICO] = sf::Color ( 136, 67, 67 );
	colorCodes[TrashTypes::PAPEL] = sf::Color::Blue;
	colorCodes[TrashTypes::PLASTICO] = sf::Color::Red;
	colorCodes[TrashTypes::VIDRO] = sf::Color::Green;
	colorCodes[TrashTypes::TOXICO] = sf::Color::Yellow;

	trashBinPos[TrashTypes::TOXICO] = Coord(0,0);
	trashBinPos[TrashTypes::PLASTICO] = Coord(1,0);
	trashBinPos[TrashTypes::PAPEL] = Coord(2,0);
	trashBinPos[TrashTypes::VIDRO] = Coord(0,1);
	trashBinPos[TrashTypes::ORGANICO] = Coord(1,1);


}
pg::DrawableSprite* GuiFactory::createTrashSprite ( TrashTypes type )
{

	sf::Shape* circle = new sf::CircleShape ( 10 );
	circle->setFillColor ( colorCodes[type] );
	pg::DrawableSprite* novo = new pg::ColoredShape ( circle );

	return novo;
}
pg::DrawableSprite* GuiFactory::createCanSprite ( TrashTypes t )
{
	if(trashBin[t]==0){
	    int Yoffset =33;
	    int Xoffset =53;
        int sizeX=209;
        int sizeY=317;
        int varX = 250;
        int varY=345;

        sf::Rect<int> rect=sf::Rect<int>( Xoffset + varX*trashBinPos[t].x, Yoffset+varY*trashBinPos[t].y,
                              sizeX, sizeY);

        trashBin[t] = new sf::Texture();
		if ( !trashBin[t]->loadFromFile ( TRASH_BIN_PATH,rect ) ) {
			std::cout << "unable to load" << TRASH_BIN_PATH;
		}
	}
	pg::TexturedSprite* novo = new  pg::TexturedSprite ( trashBin[t], Coord() );

	novo->getHitBox()->scale.x = 0.15;
	novo->getHitBox()->scale.y = 0.15;

	return novo;
}

DrawableSprite* GuiFactory::createGroundTexture(){
    if ( floor == 0 ) {
		floor = new sf::Texture();
		if ( !floor->loadFromFile ( FLOOR_PATH ) ) {
			std::cout << "unable to load" << FLOOR_PATH;
		}
	}
	pg::TexturedSprite* novo = new  pg::TexturedSprite ( floor, Coord() );
	novo->getHitBox()->scale.x = 0.5;
	novo->getHitBox()->scale.y = 0.5;
	return novo;

}

DrawableSprite*  GuiFactory::createRobotSprite()
{
	if ( robot == 0 ) {
		robot = new sf::Texture();
		if ( !robot->loadFromFile ( ROBOT_PATH ) ) {
			std::cout << "unable to load" << ROBOT_PATH;
		}
	}
	pg::TexturedSprite* novo = new  pg::TexturedSprite ( robot, Coord() );
	novo->getHitBox()->scale.x = 0.4;
	novo->getHitBox()->scale.y = 0.4;

	return novo;
}

pg::Polygon GuiFactory::createRect ( pg::Coord dimension, pg::Coord position )
{

	std::list<Coord> lista =  std::list<Coord>();
	Coord bottomleft = Coord();
	Coord bottomright = Coord ( dimension.x, 0 );
	Coord topright = dimension;
	Coord topleft = Coord ( 0, dimension.y );
	lista.push_back ( bottomleft );
	lista.push_back ( bottomright );
	lista.push_back ( topright );
	lista.push_back ( topleft );

	pg::Polygon novo = pg::Polygon ( lista );
	novo.position = position;
	return novo;
}

/*
pg::DrawableSprite* GuiFactory::createCanSprite ( TrashTypes t )
{
	int top = 15;
	int bottom = 5;
	int height = 30;
	int offset = 5;
	std::list<Coord> lista;
	lista.push_back ( Coord ( 0 + bottom, offset ) );
	lista.push_back ( Coord ( SIZE_X - bottom, offset ) );
	lista.push_back ( Coord ( SIZE_X - top, offset + height ) );
	lista.push_back ( Coord ( 0 + top, offset + height ) );

	pg::DrawableSprite* novo = new ColoredShape ( lista, colorCodes[t] );

	return novo;
}*/
