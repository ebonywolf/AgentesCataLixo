#include "GuiFactory.h"
#include <ProjGaia/SFML/TexturedSprite.h>
#include <ProjGaia/SFML/ColoredShape.h>
using namespace pg;


sf::Texture* GuiFactory::robot = 0;
 std::map<TrashTypes,sf::Color> GuiFactory::colorCodes= std::map<TrashTypes,sf::Color>();

GuiFactory::~GuiFactory()
{
	//dtor
}
void GuiFactory::setColorCodes (){
	colorCodes[TrashTypes::ORGANICO] = sf::Color ( 136, 67, 67 );
	colorCodes[TrashTypes::PAPEL] = sf::Color::Blue;
	colorCodes[TrashTypes::PLASTICO] = sf::Color::Red;
	colorCodes[TrashTypes::VIDRO] = sf::Color::Green;
	colorCodes[TrashTypes::TOXICO] = sf::Color::Yellow;
}
 pg::DrawableSprite* GuiFactory::createTrashSprite ( TrashTypes type){

    sf::Shape* circle= new sf::CircleShape(10);
    circle->setFillColor(colorCodes[type] );
    pg::DrawableSprite* novo = new pg::ColoredShape(circle);

    return novo;
}
  pg::DrawableSprite* GuiFactory::createCanSprite ( TrashTypes t){
    int top=15;
    int bottom=5;
    int height=30;
    int offset=5;
    std::list<Coord> lista;
    lista.push_back(Coord(0+bottom,offset));
    lista.push_back(Coord(SIZE_X-bottom,offset));
    lista.push_back(Coord(SIZE_X-top,offset+height));
    lista.push_back(Coord(0+top,offset+height));

    pg::DrawableSprite* novo = new ColoredShape(lista,colorCodes[t]);

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
