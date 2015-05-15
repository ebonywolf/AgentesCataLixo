#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include <ProjGaia/Graphics/DrawableType.h>
namespace pg
{
	template <class T>
	class DrawableObject: public pg::DrawableType, public T
	{
		public:

			DrawableObject ( const T& self, pg::Sprite* sprite ) : T ( self ), sprite ( sprite )
			{

			};
			virtual ~DrawableObject() {};
			pg::Sprite* getSprite() {return sprite;}


		protected:
			pg::Sprite* sprite;
		private:
	};
}
#endif // DRAWABLEOBJECT_H
