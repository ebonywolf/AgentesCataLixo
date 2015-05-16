#include <iostream>
#include "Gui/GuiWorld.h"
#include "Gui/GuiFactory.h"
#include <list>
#include "Factory.h"
#include "Agents/Control.h"
#include <map>
using namespace std;
using namespace pg;


int main()

{
    bool console=1;

	GuiFactory::setColorCodes();
	srand ( time ( 0 ) );

	int x = 20, y = 15;
	int quant = 20 ;
    int	roboquant = 1;

	if(console){
        cout << "digite o tamanho x e y do mapa (recomenda-se 15)" << endl;
        cin >> x >> y;

        std::cout << "digite a quantidade de lixo espalhado no mapa" << std::endl;
        cin >> quant;

        std::cout << "digite a quantidade de robos no mapa" << std::endl;
        cin >> roboquant;
	}

	std::list<Robot*> robo = Factory::createRobots(roboquant);



	World* world = new GuiWorld ( robo, Coord ( x, y ), quant, 150 );
	world->begin();






	return 0;
}
