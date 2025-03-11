#include "FaseStart.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

void FaseStart::init(){
        
        
    }

unsigned FaseStart::run(SpriteBuffer &screen)
{  
    std::string ent;
    draw(screen);
    system("clear");
    show(screen);
    while(true){
    
        getline(std::cin, ent);
      
        if(ent == "w"){
            
            return END_GAME;
            
            
        
        }
        else if(ent == "s"){
            
        }
        else if(ent == "q"){

        
        }

        
        
        update();
        draw(screen);
        system("clear");
        show(screen);
        
    }


                                                                                                                                                                                                                                                          


}
bool FaseStart::colideComBloco() const
{

}


/*

bool FaseLevel1::colideComBloco() const
{
	for (auto it = colisoes.begin() ; it != colisoes.end() ; ++it)
		if (hero->colideCom(**it)) {
			return true;
		}
	
	if (hero->colideCom(*porta) && !porta->isOpen() )
		return true;
	
	return false;
}

*/