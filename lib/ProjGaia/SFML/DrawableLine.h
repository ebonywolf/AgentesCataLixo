#ifndef DRAWABLELINE_H
#define DRAWABLELINE_H
#include <ProjGaia/Tools/LineSeg.h>

#include <SFML/Graphics/RectangleShape.hpp>

#include "ColoredShape.h"

namespace pg{
class DrawableLine: public ColoredShape
{
	public:
		DrawableLine ( pg::LineSeg*, sf::Color );
		void update();

		virtual ~DrawableLine();
	protected:
		pg::LineSeg* line;
	private:
};
}
#endif // DRAWABLELINE_H
