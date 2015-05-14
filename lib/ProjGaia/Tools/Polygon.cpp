#include "Polygon.h"
#include "LineSeg.h"


using namespace pg;
using namespace std;
namespace pg{
Polygon::Polygon ( list<LineSeg> axis ) {
	this->axis = axis;

}
Polygon::Polygon ( list<Coord> vertexs ) : axis ( list<LineSeg>() ) {

	bool first = false;
	Coord A, B;
    for ( auto x: vertexs ) {
		if ( first ) {
			B = x;
			LineSeg novo ( A, B );
			axis.push_back ( novo );
		}
		A = x;
		first = true;

	}
	A = vertexs.front();
	B = vertexs.back();
	LineSeg novo ( B, A );
	axis.push_back ( novo );

}

Polygon::~Polygon()
{
	//dtor
}
list<LineSeg> Polygon::getLines() {
	list<LineSeg> novo = list<LineSeg>();
    for ( auto x: this->axis ) {
		LineSeg novaLinha = x;
		novo.push_back ( novaLinha );

	}
	return novo;


}



bool Polygon::pointBelongsTo ( Coord c ) {

	LineSeg seg = axis.front();

	Coord middle = seg.getVector() * 0.5 + seg.getStart();

	seg = LineSeg ( c, middle ); ///faz uma linha do ponto c até o meio de uma aresta do poligono.

	int count = 0;
for ( auto w: axis ) {
		double time = w.timeToInterSect ( seg );
		double time2 = seg.timeToInterSect ( w );

		if ( time2 > 0  && time <= 1 && time >= 0 ) {
			count++;

		}
	}

	if ( count % 2 == 0 ) return false;
	return true;
}
}
