#ifndef GUIWORLD_H
#define GUIWORLD_H

#include <ProjGaia/SFML/MultiSprite.h>
#include <SFML/Graphics/Sprite.hpp>
#include <ProjGaia/Graphics/DrawableType.h>
#include <ProjGaia/SFML/Renderer.h>
#include <list>
#include "World.h"
#include <unordered_map>


class GuiWorld: public pg::DrawableType, public World
{

	public:


		GuiWorld ( std::list<Robot*> robots, pg::Coord size=pg::Coord(10,10),int trashNum =50,int sleepTime=250, pg::Listener<pg::KeyBoardEvent>* kbreader=0 );
		virtual ~GuiWorld();

		pg::Sprite* getSprite() {return sprite;}
	protected:
	    int sleeptime;
		virtual   void generateTrash();
		virtual   void createTrashCans();
		virtual   void updateAgents();
		void destroyTrash ( Trash* );
		void ini();
		void turn();
		void updateGraphicCoords();

		pg::Renderer* render;
		std::vector<sf::Drawable*> textures;
		pg::MultiSprite* sprite;

		std::map<Trash*, DrawableType*>drawableTrash;
		std::map<Robot*, DrawableType*>drawableRobot;
		std::map<TrashCan*, DrawableType*>drawableCan;



	private:
};

#endif // GUIWORLD_H
