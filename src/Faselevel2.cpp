#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "Faselevel2.hpp"

void Faselevel2::init(){
    
    fase2_[0]= new ObjetoDeJogo("fase1",Sprite("rsc/parede_esquerda.img",COR::CINZA_ESCURA),-6,0);
    objs.push_back(fase2_[0]);
    fase2_[1] = new ObjetoDeJogo("fase1",Sprite("rsc/parede_cima.img",COR::CINZA_ESCURA),80,0);
    objs.push_back(fase2_[1]);
   
    
    vida = new ObjetoDeJogo(" vida", Sprite("rsc/vida.img",COR::VERMELHA),1,98);
    objs.push_back(vida);
    fase2_[2] = new ObjetoDeJogo("fase1",Sprite("rsc/castleBlock5.img",COR::CINZA_ESCURA),70,0);
    objs.push_back(fase2_[2]);
    fase2_[3] = new ObjetoDeJogo("fase1",Sprite("rsc/Escada.img",COR::CIANO),73,40);
    objs.push_back(fase2_[3]);
    heroi = new Heroi(ObjetoDeJogo("Heroi", SpriteAnimado("rsc/Meu_Heroi_Lado.img",1,COR::CIANO),73,60));
    objs.push_back(heroi);
    dragao = new Dragao(ObjetoDeJogo("Heroi", SpriteAnimado("rsc/dragao.img",1,COR::VERDE),68,130));
    objs.push_back(dragao);
    bola = new ObjetoDeJogo("fase1",Sprite("rsc/fogo.img",COR::VERMELHA),76,110);
    objs.push_back(bola);
}

unsigned Faselevel2::run(SpriteBuffer &screen)
{  
    std::string ent;
    draw(screen);
    system("clear");
    show(screen);
    while(true){
        std::string numeroString = std::to_string(heroi->getLife());
        coracao = new ObjetoDeJogo("Bau",TextSprite(numeroString,COR::VERMELHA),2,107);
        objs.push_back(coracao);
        getline(std::cin, ent);
        if(heroi->getLife() <=0){
            return GAME_OVER;
        }
        if(dragao->get_vida()<=0){
            return END_GAME;
        }
       
        if(ent == "a"){
            if(( heroi->getPosC() > 27 && heroi->getPosC()<63)){
              heroi->moveUp(1);
              heroi->moveLeft(3);}
            else{
                heroi->moveLeft(3);
            }
        }
        
        else if(ent == "d"){
            if(( heroi->getPosC() > 27 && heroi->getPosC()<63)){
                heroi->moveDown(1);
                heroi->moveRight(3);}
              else{
                  heroi->moveRight(3);
              }

        
        }
        else if(ent == "q"){
        }
        if(heroi->colideComBordas(*dragao)){
            dragao->tirar_vida(heroi->atacar());
        }
    
        
        if(!bola->colideCom(*heroi) && !bola->colideCom(*fase2_[0])  ){
            
            bola->moveLeft(4);

        }else{
            heroi->tirarvida(30);
            bola->desativarObj();
            
           
            }

        if(get_counter() == 40){
            std::cout << "entrou";
            bola = new ObjetoDeJogo("fase1",Sprite("rsc/fogo.img",COR::VERMELHA),76,110);
            objs.push_back(bola);
        }
        

    
        if(get_counter() > 40){
            reiniciar_counter();
        }

        
        std::cout << get_counter();
        incrementar_counter();
        update();
        draw(screen);
        system("clear");
        show(screen);
        std::cout <<heroi->getPosC()<<"coluna"<<std::endl;
        std::cout<<heroi->getPosL()<<"linha"<<std::endl;
        std::cout<<dragao->get_vida()<<"linha"<<std::endl;
    }


                                                                                                                                                                                                                                                          


}
bool Faselevel2::colideComBloco() const
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