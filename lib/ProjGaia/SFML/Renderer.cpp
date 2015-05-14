#include "Renderer.h"
#include <cmath>

#include <ctime>
#include <cstdlib>
//#include <iostream>

#include <ProjGaia/Tools/Coord.h>

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <ProjGaia/Tools/KeyBoardEvent.h>
#include <ProjGaia/Tools/NeedsUpdate.h>
#include <thread>
#include <chrono>


using namespace sf;
using namespace pg;
namespace pg
{
	Renderer::Renderer ( std::string name , Camera* camera, pg::Coord tam , pg::Coord dim ) :
		camera ( camera ), dimX ( dim.x ), dimY ( dim.y ), tam ( tam ), name ( name )

	{
	    window=0;
	    assync=0;

	}

	Renderer::~Renderer()
	{
		delete ( window );
		delete ( assync );
	}
	pg::Coord Renderer::getMouseCoord()
	{
		pg::Coord x = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );
		if ( camera != 0 ) {
			pg::Coord dimension = pg::Coord ( window->getSize().x, window->getSize().y );

			//ajuste de acordo com a camera
			x = ( dimension / 2 - dimension / ( camera->zoom * 2 ) ) + x / camera->zoom;

			//ajuste de acordo com a resolução
			pg::Coord resolution = pg::Coord ( window->getDefaultView().getSize().x, window->getDefaultView().getSize().y ) ;
			resolution = dimension / resolution;
			x = x / resolution;

			x = x + camera->pos;
		}
		return x;

	}
	void Renderer::createCharEvents (Event event )
	{
		if ( event.type == sf::Event::TextEntered ) {
			if ( event.text.unicode < 128 ) {
				char a = static_cast<char> ( event.text.unicode ) ;
				pg::Observer<char>::notifyListeners ( a );
			}
		}
	}

	void Renderer::createMouseEvent ( sf::Event e )
	{
		switch ( e.type ) {
			case Event::MouseButtonPressed: {
					pg::Coord coord = getMouseCoord();
					pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );


					if ( Mouse::isButtonPressed ( Mouse::Left ) && !mouse[0] ) {
						MouseReader::notifyListeners ( MouseEvent ( MouseEvent::LEFT_DOWN, coord, screenCoord ) );
						mouse[0] = 1;
					}
					if ( Mouse::isButtonPressed ( Mouse::Middle ) && !mouse[1] ) {
						MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MIDDLE_DOWN, coord, screenCoord ) );
						mouse[1] = 1;
					}
					if ( Mouse::isButtonPressed ( Mouse::Right ) & !mouse[2] ) {
						MouseReader::notifyListeners ( MouseEvent ( MouseEvent::RIGHT_DOWN, coord, screenCoord ) );
						mouse[2] = 1;
					}
					break;

				}
			case Event::MouseButtonReleased: {
					pg::Coord coord = getMouseCoord();
					pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );

					if ( !Mouse::isButtonPressed ( Mouse::Left ) && mouse[0] ) {
						MouseReader::notifyListeners ( MouseEvent ( MouseEvent::LEFT_UP, coord, screenCoord ) );
						mouse[0] = 0;
					}
					if ( !Mouse::isButtonPressed ( Mouse::Middle ) && mouse[1] ) {
						MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MIDDLE_UP, coord, screenCoord ) );
						mouse[1] = 0;
					}
					if ( !Mouse::isButtonPressed ( Mouse::Right ) && mouse[2] ) {
						MouseReader::notifyListeners ( MouseEvent ( MouseEvent::RIGHT_UP, coord, screenCoord ) );
						mouse[2] = 0;
					}
					break;

				}

			case Event::MouseMoved: {
					pg::Coord coord = getMouseCoord();
					pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );

					MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MOVE, coord, screenCoord ) );
					break;
				}
			case Event::MouseWheelMoved: {
					// 	float x=((Event::MouseWheelEvent)e).delta;
					pg::Coord coord = getMouseCoord();
					pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );
					//e.mouseWheel;
					//       MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MOVE, coord, screenCoord ) );

				}

		}

	}


	void Renderer::createKeyBoardEvent ( sf::Event e )
	{

		if ( Event::KeyPressed ) {
			//  std::<<"here";
			for ( int i = 0; i < 100; i++ ) {
				if ( sf::Keyboard::isKeyPressed ( ( Keyboard::Key ) i ) && !keyboard[i] ) {

					KeyBoardReader::notifyListeners ( KeyBoardEvent ( i, KeyBoardEvent::DOWN ) );

					keyboard[i] = true;
				}

			}

		}
		if ( Event::KeyReleased ) {
			for ( int i = 0; i < 100; i++ ) {
				if ( !sf::Keyboard::isKeyPressed ( ( Keyboard::Key ) i ) && keyboard[i] ) {

					KeyBoardReader::notifyListeners ( KeyBoardEvent ( i, KeyBoardEvent::UP ) );

					keyboard[i] = false;
				}

			}
		}
	}
	int Renderer::getHeight()
	{
		return window->getSize().y;

	}
	int Renderer::getWidth()
	{
		return window->getSize().x;

	}
	void Renderer::beginAssync()
	{
		auto func = [this]() {this->begin();};
		assync = new std::thread ( func );
		assync->detach();
	}
	void Renderer::end()
	{
		active = false;
	}
	void Renderer::begin()
	{
		ContextSettings contextSettings;
		contextSettings.depthBits = 32;
		window = new RenderWindow ( VideoMode ( tam.x, tam.y ), name, Style::Default, contextSettings );

		active = true;
		window->setActive();

		glClearDepth ( 0xff );
		glClearColor ( 0xff, 0xff, 0xff, 0xff );

		bool kb[256] = {0};
//    sprite.getOrigin(0,0);
		while ( window->isOpen() ) {
			for ( auto x : syncList ) {
				x->update ( 0 );

			}

			Event event;
			while ( window->pollEvent ( event ) ) {
				if ( event.type == Event::Closed || !active ) {
					window->close();
				}
				createMouseEvent ( event );
				createKeyBoardEvent ( event );
				createCharEvents ( event );
				if ( event.type == Event::Resized ) {
				}
			}
			std::this_thread::sleep_for ( std::chrono::milliseconds ( 16 ) );

			window->clear ( Color ( 0x00, 0x00, 0x00, 0x00 ) );

			drawSprites();

			window->display();
		}
	}
	void Renderer::addDrawable ( DrawableType* d )
	{
		sprites.push_back ( d );
	}
	void Renderer::removeDrawable ( DrawableType* d )
	{
		sprites.remove ( d );
	}
	void Renderer::addSync ( NeedsUpdate* u )
	{
		this->syncList.push_back ( u );
	}
	void Renderer::drawSprites()
	{

		View v = window->getView();
		v.setRotation ( camera->rotation );
		v.setCenter ( dimX / 2 + camera->pos.x , dimY / 2 + camera->pos.y );
		v.setSize ( dimX / camera->zoom, dimY / camera->zoom );
		window->setView ( v );
		//  v.setSize()
//   view.setCenter(  , camera->pos.y);
		//  view = View(Vector2f(  dimX/2 + camera->pos.x ,dimY/2 + camera->pos.y  ),Vector2f(dimX,dimY));
		//std::cout<<view.getCenter().x<<std::endl;

		for ( DrawableType * type : sprites ) {
			DrawableSprite* s = ( DrawableSprite* ) type->getSprite();
			if(s!=0){
                s->update ( 0 );
                window->draw ( *s );
			}else{
                std::cout<< "Attempting to draw null object" <<std::endl;
			}

		}
		for ( auto x : debugDraw ) {
			window->draw ( *x );

		}

	}
}
