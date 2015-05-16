#include <iostream>
#include "GuiWorld.h"
#include "GuiFactory.h"
#include <list>
#include "Factory.h"
#include "Control.h"
#include <map>
using namespace std;
using namespace pg;


int main()

{


	GuiFactory::setColorCodes();
	srand ( time ( 0 ) );
	std::list<Robot*> robo =Factory::createRobots();
	cout<<"digite o tamanho x e y do mapa (recomenda-se 15)"<<endl;
	int x=20,y=15;
	cin>>x>>y;
	std::cout<< "digite a quantidade de lixo espalhado no mapa" <<std::endl;
	int quant=20 ;
	cin>>quant;



	World* world = new GuiWorld ( robo, Coord ( x, y ),quant,150 );
	world->begin();






	return 0;
}
