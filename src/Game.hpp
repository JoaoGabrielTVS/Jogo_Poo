#ifndef GAME_HPP
#define GAME_HPP
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Cores.hpp"
#include "FaseLevel1.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(250,85);//representa uma tela em branco onde tudo vai esta sendo escrito 
		FaseLevel1 fase1("Fase",Sprite("rsc/Meu_fase1.img",COR::CINZA_ESCURA));
		
		fase1.init();
		int ret1 = fase1.run(buffer);
		


		std::cout << "Saindo..." << std::endl;
			
}
};

#endif // GAME_HPP
