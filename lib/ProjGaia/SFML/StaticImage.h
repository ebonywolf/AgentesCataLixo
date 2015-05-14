#ifndef STATICIMAGE_H
#define STATICIMAGE_H
#include <ProjGaia/Graphics/DrawableType.h>
#include "DrawableSprite.h"

namespace pg{
class StaticImage: public DrawableType
{
	public:
		/** Default constructor */
		StaticImage ( DrawableSprite* sprite ) : sprite ( sprite ) {}
		/** Default destructor */
		virtual ~StaticImage();
		pg::Sprite* getSprite() { return sprite;}
	protected:
		DrawableSprite* sprite;
	private:
};
}
#endif // STATICIMAGE_H
