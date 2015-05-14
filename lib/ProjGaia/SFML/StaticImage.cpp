#include "StaticImage.h"
namespace pg {
StaticImage::~StaticImage()
{
	delete ( sprite );
}
}
