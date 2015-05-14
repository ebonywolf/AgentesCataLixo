#ifndef LINESEG_H
#define LINESEG_H
#include "Coord.h"

namespace pg {
	class LineSeg
	{

		public:
			/** Default constructor */


			LineSeg();
			LineSeg ( pg::Coord start, pg::Coord end );
			LineSeg ( pg::Coord start, double angle, double speed );
			LineSeg ( pg::Coord vetor );
			LineSeg ( double angle, double speed );
			virtual ~LineSeg();

			void moveStart ( double time );
			void rotate ( double arc );
			bool isParallel ( LineSeg );
			bool pointBelongsTo ( pg::Coord );
			double getTimetoPoint ( pg::Coord );
			pg::Coord interSect ( LineSeg );
			double timeToInterSect ( LineSeg );


			void setVector ( pg::Coord );
			void setSpeed ( double );
			void setAngle ( double );
			void setStart ( pg::Coord coord ) {start = coord;};

			pg::Coord getVector() {return vector;}
			double getSpeed() {return speed;}
			double getAngle() {return angle;}
			pg::Coord getStart() {return start;}

			LineSeg operator+ ( LineSeg );
			LineSeg operator- ( LineSeg );
			bool operator== ( LineSeg );
			bool operator!= ( LineSeg );

		protected:
			pg::Coord vector;
			pg::Coord end;
			double speed;
			pg::Coord start;
			double angle;
		private:
			void updateSpeed();
			void updateVector();
			void updateAngle();
	};
}
#endif // LINESEG_H
