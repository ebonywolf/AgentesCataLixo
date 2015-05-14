#ifndef RENDERER_H
#define RENDERER_H



#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ProjGaia/Graphics/KeyBoardReader.h>
#include <ProjGaia/Graphics/MouseReader.h>
#include <iostream>
#include <list>
#define ClickTime 400

#include <ProjGaia/Tools/Observer.h>
#include <ProjGaia/Tools/MouseEvent.h>
#include "DrawableSprite.h"
#include <ProjGaia/Graphics/Camera.h>
#include <ProjGaia/Graphics/DrawableType.h>
#include <ProjGaia/Graphics/PainterType.h>
#include <ProjGaia/Graphics/WindowType.h>
#include <thread>
class NeedsUpdate;

namespace pg{
class Renderer : public WindowType,public PainterType, public MouseReader,public KeyBoardReader, public Observer<char>
{
	public:
		int dimX;
		int dimY;

		Renderer ( std::string window_name, Camera* camera , pg::Coord tam, pg::Coord dim );
		pg::Coord getMouseCoord();
		virtual ~Renderer();
        int getWidth();
        int getHeight();


		void removeDrawable ( DrawableType* );
		void addDrawable ( DrawableType* );
		void addSync(NeedsUpdate*);
		void begin();
		void beginAssync();
		void end();
		std::list<sf::Drawable*> debugDraw = std::list<sf::Drawable*>();
	protected:
		void createMouseEvent ( sf::Event );
		void createKeyBoardEvent ( sf::Event );
        void createCharEvents(sf::Event);


		sf::RenderWindow* window;
		std::list<DrawableType*> sprites = std::list<DrawableType*>();
		std::list<NeedsUpdate*> syncList=std::list<NeedsUpdate*>();

		void drawSprites();


		Camera* camera;
	private:
	    std::thread* assync=0;

	    std::string name;
	    pg::Coord tam;

	    bool active=false;
		bool mouse[3] = {0, 0, 0}; //mouse timers
		bool keyboard[100] = {0};



};
}
#endif // WINDOW_H
