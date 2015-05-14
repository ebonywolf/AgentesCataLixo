#ifndef CAMERA_H
#define CAMERA_H
#include "../Tools/Coord.h"
//TODO :Camera field of view
namespace pg{
class Camera
{
	public:
		Camera();
		virtual ~Camera();

		double zoom = 1;
		double rotation = 0;
		pg::Coord pos;

	protected:
	private:
};

}
#endif // CAMERA_H
