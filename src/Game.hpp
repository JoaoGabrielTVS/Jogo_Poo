#ifndef GAME_HPP
#define GAME_HPP
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Cores.hpp"
#include "FaseLevel1.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "FaseStart.hpp"
#include "Faselevel2.hpp"
class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(250,85);//representa uma tela em branco onde tudo vai esta sendo escrito 
		
		FaseStart fase_s("Fase",Sprite("rsc/tela_inicio.img",COR::VERMELHO_C));
		fase_s.init();
		fase_s.run(buffer);
		system("clear");
		buffer.clear();
		FaseLevel1 fase1("Fase",Sprite("rsc/Meu_fase1.img",COR::CINZA_ESCURA));
	
		
		fase1.init();
		fase1.run(buffer);
		buffer.clear();
		
		Faselevel2 fase2("Fase",Sprite("rsc/Meu_fase2.img",COR::CINZA_ESCURA));
		fase2.init();
		fase2.run(buffer);
		buffer.clear();
        /*
		Faselevel2 fase2("Fase",Sprite("rsc/Vitoria.img",COR::CINZA_ESCURA));
		fase2.init();
		fase2.run(buffer);
		buffer.clear();                          
		std::cout << "Saindo..." << std::endl;
	*/
}
};

#endif // GAME_HPP
