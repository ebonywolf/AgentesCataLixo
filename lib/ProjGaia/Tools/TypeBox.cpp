#include "TypeBox.h"

#define BACKSPACE 8
TypeBox::TypeBox()
{
	phrase = "_";
	active = false;

}

TypeBox::~TypeBox()
{

}
void TypeBox::activate()
{
	active = true;
}
void TypeBox::deactivate()
{
	active = false;
}

void TypeBox::notify ( char k )
{
	phrase.resize ( phrase.length() - 1 );
	if ( k == BACKSPACE && phrase.length() > 0 ) {
		phrase.resize ( phrase.length() - 1 );

	} else {
	    if(k>15)
		phrase += k;
	}
	phrase += '_';

}
