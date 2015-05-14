#ifndef DRAWABLETYPE_H
#define DRAWABLETYPE_H
namespace pg {
	class Sprite;

class DrawableType
{
	public:
		/** Default constructor */

		/** Default destructor */
		virtual ~DrawableType(){};

		virtual pg::Sprite* getSprite() = 0;
	protected:

	private:
};
}

#endif // DRAWABLETYPE_H
