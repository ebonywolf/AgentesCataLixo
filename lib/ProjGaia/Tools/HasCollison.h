#ifndef HASCOLLISON_H
#define HASCOLLISON_H
#include "HitBox.h"

namespace pg{
class HasCollison
{
	public:

        virtual ~HasCollison()=default;

		virtual HitBox* getHitBox() =0;

	protected:
	private:
};
}
#endif // HASCOLLISON_H
