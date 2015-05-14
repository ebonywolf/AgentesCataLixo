#include "Coord.h"
#include "math.h"
using namespace pg;

namespace pg{
Coord::Coord ( double x, double y ) : x ( x ), y ( y )
{
}

Coord::~Coord()
{
	//dtor
}
double Coord::distance ( Coord b ) {
	double t = b.x - this->x;
	double u = b.y - this->y;
	t *= t;
	u *= u;
	return pow ( t + u, 0.5 );

}
bool Coord::operator== ( Coord b ) {
	if ( this->x != b.x ) return 0;
	if ( this->y != b.y ) return 0;
	return 1;

}
void Coord::operator*= ( double b ) {
	this->x *= b;
	this->y *= b;

}
bool Coord::operator!= ( Coord b ) {
	if ( this->x != b.x ) return 1;
	if ( this->y != b.y ) return 1;
	return 0;

}
void Coord::move ( double angle, double speed ) {
	x = x + speed * cos ( angle );
	y = y + speed * sin ( angle );

}
void Coord::operator+= ( Coord c ) {
	this->x += c.x;
	this->y += c.y;
}
void Coord::operator-= ( Coord c ) {
	this->x -= c.x;
	this->y -= c.y;
}
Coord Coord::operator* ( double k ) {
	return Coord ( x * k, y * k );

}

Coord Coord::operator/ ( double k ) {
	return   Coord ( x / k, y / k );
}

Coord Coord::operator+ ( Coord b ) {
	return Coord ( this->x + b.x, this->y + b.y );
}
Coord Coord::operator- ( Coord b ) {
	return Coord ( this->x - b.x, this->y - b.y );
}
Coord Coord::operator* ( Coord b ) {
	return Coord ( this->x * b.x, this->y * b.y );
}
Coord Coord::operator/ ( Coord b ) {
	return Coord ( this->x / b.x, this->y / b.y );
}
double Coord::modulo() {
	return pow ( x * x + y * y, 0.5 );
}
namespace pg {
	std::ostream& operator<< ( std::ostream& os , const Coord& p ) {
		os << "X:" << p.x << "  Y:" << p.y;
		return os;

	}
}
}
