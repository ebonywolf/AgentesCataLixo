#include "GuiWorld.h"
#include "GuiFactory.h"

#include <ProjGaia/SFML/HollowShape.h>
#include <ProjGaia/SFML/DrawableObject.h>
//#include <ProjGaia/Tools/Coord.h>
#define ROBOT_POS_OFFSET Coord(10,4)
#define TRASH_POS_OFFSET Coord(10,4)
#define CAN_POS_OFFSET Coord(10,4)
using namespace pg;
GuiWorld::GuiWorld ( std::list<Robot*> robots, pg::Coord size ) : World ( robots, size )
{
	sprite = new MultiSprite();
	render = new Renderer ( "CataLixo", new Camera(), WINDOW_SIZE, WINDOW_SIZE );

//    sprites=GuiFactory::getGroundTextures();
	for ( int i = 0; i < size.x; i++ ) {
		for ( int j = 0; j < size.y; j++ ) {
			sprite->add (
			    new HollowShape (
			        GuiFactory::createRect (
			            Coord ( SIZE_X, SIZE_Y ),
			            Coord ( i * SIZE_X, j * SIZE_Y )
			        ),
			        sf::Color::Blue, 5 )
			);
		}
	}
	for ( auto x : this->robots ) {
		DrawableObject<Robot>* novo = new DrawableObject<Robot> ( *x, GuiFactory::createRobotSprite() );
		drawableRobot[x] = novo;

	}
}
void GuiWorld::ini(){
    World::ini();
    render->addDrawable ( this );

	for ( auto x : trashCans ) {
	//	render->addDrawable ( drawableCan[x] );
	}
	for ( auto x : trash ) {
	//	render->addDrawable ( drawableTrash[x] );
	}
	for ( auto x : robots ) {
		render->addDrawable ( drawableRobot[x] );
	}
	render->beginAssync();

}

void  GuiWorld::generateTrash()
{
	World::generateTrash();
	for ( auto x : trash ) {
		DrawableObject<Trash>* novo = new DrawableObject<Trash> ( *x, GuiFactory::createTrashSprite() );
		drawableTrash[x] = novo;
	}

}
void GuiWorld::createTrashCans()
{
	World::createTrashCans();
	for ( auto x : trashCans ) {
		DrawableObject<TrashCan>* novo = new DrawableObject<TrashCan> ( *x, GuiFactory::createCanSprite() );
		drawableCan[x] = novo;
	}


}
void  GuiWorld::updateAgents()
{
    World::updateAgents();

}
void GuiWorld::updateGraphicCoords()
{

	for ( auto t : trash ) {
        Coord pos=t->getPosition();
		Coord gcoord = Coord ( pos.x * SIZE_X, pos.y * SIZE_Y )+TRASH_POS_OFFSET;

	//	drawableTrash[t]->getSprite()->getHitBox()->position = gcoord;
	}
	for ( auto t : robots ) {
		Coord pos=t->getPosition();
		Coord gcoord = Coord ( pos.x * SIZE_X, pos.y * SIZE_Y )+ROBOT_POS_OFFSET;

		drawableRobot[t]->getSprite()->
            getHitBox()->position = gcoord;
	}
	for ( auto t : trashCans ) {
		Coord pos=t->getPosition();
		Coord gcoord = Coord ( pos.x * SIZE_X, pos.y * SIZE_Y )+CAN_POS_OFFSET;

		//drawableCan[t]->getSprite()->getHitBox()->position = gcoord;
	}

}
void GuiWorld::turn()
{
	updateGraphicCoords();
	sf::sleep(sf::milliseconds(250));
	World::turn();

}

GuiWorld::~GuiWorld()
{
	//dtor
}
