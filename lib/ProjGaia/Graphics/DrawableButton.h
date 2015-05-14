#ifndef DRAWABLEBUTTON_H
#define DRAWABLEBUTTON_H
#include "../Tools/Button.h"
#include "DrawableType.h"
#include "Text.h"

namespace pg{
class DrawableButton : public Button, DrawableType
{
	public:
		/** Default constructor */
		DrawableButton ( pg::Sprite* main, pg::Sprite* off, pg::Sprite* half, Text* text );
		/** Default destructor */
		virtual ~DrawableButton();
		virtual pg::Sprite* getSprite();
		pg::Sprite *main, *off, *half;
		Text* text;
	protected:

	private:
};
}
#endif // DRAWABLEBUTTON_H
