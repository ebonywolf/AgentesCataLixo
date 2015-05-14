#ifndef TEXT_H
#define TEXT_H
#include "DrawableType.h"
#include "../Tools/Coord.h"
#include "iostream"
#define String std::string

namespace pg{
class Text: public DrawableType {
	public:
		/** Default constructor */
		Text ( String text, float size, String font, pg::Coord pos );
		/** Default destructor */
		virtual ~Text();
		float size;
		String text, font;
		pg::Coord pos;
	protected:

	private:
};
}

#endif // TEXT_H
