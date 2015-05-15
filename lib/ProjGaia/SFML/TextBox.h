#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "DrawableSprite.h"
#include "ColoredShape.h"

#include <ProjGaia/Graphics/DrawableType.h>
#include <ProjGaia/Tools/Coord.h>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
namespace pg
{
	class TextBox: public pg::DrawableSprite
	{
		public:
			TextBox ( pg::Coord dimension, pg::Coord pos,
			          sf::Color color, sf::Font* font, std::string text,
			          sf::Color textColor = sf::Color ( 255, 255, 255 ) );

			virtual ~TextBox();
			void update ( void* );
			void draw ( sf::RenderTarget&, sf::RenderStates ) const ;


		protected:
			pg::ColoredShape* box;
			sf::Text* text;

		private:
	};
}
#endif // TEXTBOX_H
