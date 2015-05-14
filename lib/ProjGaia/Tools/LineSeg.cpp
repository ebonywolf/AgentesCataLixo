#include "LineSeg.h"
#include <math.h>
#include "Angle.h"

#define M_PI		3.14159265358979323846

using namespace pg;

namespace pg{
LineSeg::LineSeg() :
	vector ( Coord ( 0, 0 ) ), start ( Coord ( 0, 0 ) ), speed ( 0 ), angle ( 0 ), end ( Coord ( 0, 0 ) )
{

}
LineSeg::LineSeg ( Coord start, Coord end ) :
	start ( start ), vector ( end - start ), end ( end ) {

	updateSpeed();
	updateAngle();

}
LineSeg::LineSeg ( Coord start, double angle, double speed )
	: start ( start ), speed ( speed ), angle ( angle ), end ( Coord() ) {
	updateVector();
}
LineSeg::LineSeg ( Coord vetor ) :
	vector ( vetor ), start ( Coord() ), end ( Coord() ) {
	updateAngle();
	updateSpeed();
	end.x = start.x + speed * cos ( angle );
	end.y = start.y + speed * cos ( angle );
}
LineSeg::LineSeg ( double angle, double speed )
	: angle ( angle ), speed ( speed ), start ( Coord() ), end ( Coord() ) {
	updateVector();
}

LineSeg::~LineSeg() {

}

void LineSeg::setVector ( Coord coord ) {
	vector = coord;
	updateSpeed();
	updateAngle();
	end.x = start.x + speed * cos ( angle );
	end.y = start.y + speed * cos ( angle );
}
void LineSeg::LineSeg::setSpeed ( double _speed ) {
	speed = _speed;
	updateVector();


}
void LineSeg::setAngle ( double _angle ) {
	angle = _angle;
	updateVector();
}

LineSeg LineSeg::operator+ ( LineSeg line ) {
	LineSeg novo;
	novo.setVector ( this->vector + line.vector );
	novo.setStart ( this->start + line.start );
	novo.updateAngle();
	novo.updateSpeed();
	return novo;

}
LineSeg LineSeg::operator- ( LineSeg line ) {
	LineSeg novo;
	novo.setVector ( this->vector - line.vector );
	novo.setStart ( this->start - line.start );
	novo.updateAngle();
	novo.updateSpeed();
	return novo;
}

bool LineSeg::operator== ( LineSeg line ) {
	if ( vector == line.vector && start == line.start ) return true;
	return false;
}
bool LineSeg::operator!= ( LineSeg line ) {
	return ! ( *this == line );
}
void  LineSeg::updateSpeed() {
	speed = vector.modulo();
}

void  LineSeg::updateVector() {
	vector.x = start.x + speed * cos ( angle );
	vector.y = start.y + speed * sin ( angle );
}
void  LineSeg::updateAngle() {


	angle = atan ( vector.y / vector.x );
	if ( vector.x < 0 ) angle = Angle::invertAngle ( angle );
}
void LineSeg::moveStart ( double time ) {
	start.move ( angle, time * speed );
}
void LineSeg::rotate ( double arc ) {
	angle = angle + arc;
	while ( angle >= 2 * PI ) {
		angle -= 2 * PI;
	}
	while ( angle <= -2 * PI ) {
		angle += 2 * PI;
	}
}
bool LineSeg::isParallel ( LineSeg line ) {
	if ( Angle::shortestAngle ( angle ) == Angle::shortestAngle ( line.angle ) ) return true;
	return false;
}
bool LineSeg::pointBelongsTo ( Coord coord ) {
	double a = getTimetoPoint ( coord );
	if ( isinf ( a ) ) return false;
	return true;

}
double LineSeg::getTimetoPoint ( Coord coord ) {
	/** c*V + start= Coord
	c*V.x + start.x= Coord.x
	c*V.y + start.y= Coord.y
	 */
	Coord var = ( coord - start );
	double f = var.x / vector.x;
	if ( var.x == 0 ) f = 0;

	double g = var.y / vector.y;
	if ( var.y == 0 ) g = 0;

	if ( f == g ) return f;

	if ( vector*g + start == coord ) return g;
	if ( vector*f + start == coord ) return f;

	return 1.0 / 0.0;

}
Coord LineSeg::interSect ( LineSeg line ) {
	double j = timeToInterSect ( line );
	Coord cross = vector * j + start;
	return cross;
}
double LineSeg::timeToInterSect ( LineSeg line ) {
	double m[2][3];

	m[0][0] = this->vector.x;
	m[1][0] = this->vector.y;

	m[0][1] = -line.vector.x;
	m[1][1] = -line.vector.y;
	//TODO :Consertar Gambiarra
	//GAMBIARRA
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			if ( m[i][j] == 0 ) m[i][j] += 0.0000001;

		}


	}
	//FIM DE GAMBIARRA


	//det verifica se é paralelo
	int det = m[0][0] * m[1][1] - ( m[1][0] * m[0][1] );
	if ( det == 0 ) return 1.0 / 0.0;

	m[0][2] = -this->start.x + line.start.x;
	m[1][2] = -this->start.y + line.start.y;



	//descobre y
	double mult = m[1][0] / m[0][0];
	for ( int i = 0; i < 3; i++ ) {
		m[1][i] = m[1][i] - m[0][i] * mult;
	}
	//descobre x
	mult = m[0][1] / m[1][1];
	for ( int i = 0; i < 3; i++ ) {
		m[0][i] = m[0][i] - m[1][i] * mult;

	}
	double j = m[0][2] / m[0][0];
	// double u=m[1][2]/m[1][1];
	return j;
}
}
