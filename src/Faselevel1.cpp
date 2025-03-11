#include "FaseLevel1.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

void FaseLevel1::init(){
    tapete = new ObjetoDeJogo("Tapete", Sprite("rsc/tapete.img", COR::PRETA),6,120);
    objs.push_back(tapete);
    fase1_[0]= new ObjetoDeJogo("fase1",Sprite("rsc/parede_esquerda.img",COR::CINZA_ESCURA),0,0);
    objs.push_back(fase1_[0]);
    fase1_[1]= new ObjetoDeJogo("fase1",Sprite("rsc/parede_esquerda.img",COR::CINZA_ESCURA),0,216);
    objs.push_back(fase1_[1]);//direita


    fase1_[2]= new ObjetoDeJogo("fase1",Sprite("rsc/parede_baixoqueb.img",COR::CINZA_ESCURA),77,0);
    objs.push_back(fase1_[2]);
    fase1_[3] = new ObjetoDeJogo("fase1",Sprite("rsc/parede_central_cima.img",COR::CINZA_ESCURA),19,0);
    objs.push_back(fase1_[3]);
    fase1_[4] = new ObjetoDeJogo("fase1",Sprite("rsc/parede_central_baixo.img",COR::CINZA_ESCURA),37,115);
    objs.push_back(fase1_[4]);
    fase1_[5] = new ObjetoDeJogo("fase1",Sprite("rsc/parede_cima.img",COR::CINZA_ESCURA),0,0);
    objs.push_back(fase1_[5]);
    tapete2 = new ObjetoDeJogo("Tapete2", Sprite("rsc/tapete_deitado.img", COR::PRETA),23,135);
    objs.push_back(tapete2);
    tapete3 = new ObjetoDeJogo("Tapete3", Sprite("rsc/tapete.img", COR::PRETA),26,120);
    objs.push_back(tapete3);
    aranha = new Aranha(ObjetoDeJogo("Aranha", SpriteAnimado("rsc/Meu_Aranha.img",2),5,9));
   

    objs.push_back(aranha); 
    heroi = new Heroi(ObjetoDeJogo("Heroi", SpriteAnimado("rsc/Meu_Heroi.img",1,COR::CIANO),6,80));
    objs.push_back(heroi);
    
    Caveira_Espada[0] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),27,80));
    
    objs.push_back(Caveira_Espada[0]);
    
    Caveira_Espada[1] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),26,60));
    objs.push_back(Caveira_Espada[1]);
    
    
    flecha = new ObjetoDeJogo("flecha", Sprite("rsc/flecha_esc.img", COR::BRANCA),30,29);
    objs.push_back(flecha); 
    Caveira_Espada[2] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),8,170));//
    objs.push_back(Caveira_Espada[2]);
    
    Caveira_Espada[3] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),30,150));//
    objs.push_back(Caveira_Espada[3]);
    
    Caveira_Espada[4] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),40,155));//
    objs.push_back(Caveira_Espada[4]);
    
    Caveira_Espada[5] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),25,50));
    objs.push_back(Caveira_Espada[5]);
  
    Caveira_Arqueira[0] = new Inimigo_Arco(ObjetoDeJogo("Inimigo_Do_Arco", SpriteAnimado("rsc/Caveira_Arc_esc.img",1,COR::BRANCA),28, 29));
    objs.push_back(Caveira_Arqueira[0]);
	fissura = new ObjetoDeJogo("Bau", Sprite("rsc/parede_destruida.img",COR::CINZA_ESCURA),78,64);
    objs.push_back(fissura);
    chave = new ObjetoDeJogo("Chave",Sprite("rsc/Meu_chave.img",COR::VERMELHA),30,10);
	objs.push_back(chave);
    bau = new ObjetoDeJogo("Bau", Sprite("rsc/Meu_bau.img",COR::MARROM_ESCURA),6,190);
    objs.push_back(bau);
    vida = new ObjetoDeJogo(" vida", Sprite("rsc/vida.img",COR::VERMELHA),1,98);
    objs.push_back(vida);
        
    

    }

unsigned FaseLevel1::run(SpriteBuffer &screen)
{  
    std::string ent;
    draw(screen);
    system("clear");
    show(screen);
    bool estado = true;                    

                                                                                                                                                                                                                                                          

    
    while(true){
        std::string numeroString = std::to_string(heroi->getLife());
        coracao = new ObjetoDeJogo("Bau",TextSprite(numeroString,COR::VERMELHA),2,107);
        objs.push_back(coracao);
        if(heroi->getPosL() == 72 && heroi->getchave()==true){
           return END_GAME;
        }
        
        std::cout<<heroi->getPosC()<<"essa é a coluna"<<std::endl;
        std::cout<<heroi->getPosL()<<"essa é a linha"<<std::endl;
        getline(std::cin, ent);
        int posL = heroi->getPosL() , posC = heroi->getPosC();
        if(ent == "w" && !(heroi->getPosL() ==2) &&  (heroi->getPosL()==10 ||!heroi->colideComBordas(*fase1_[5])&&  !heroi->colideComBordas(*fase1_[3])|| (heroi->getPosL()>=10 && heroi->getPosC()<156 && heroi->getPosC()>116))){
            heroi->moveUp(6);
        
        }else if(ent == "d" && ((!heroi->colideComBordas(*fase1_[4]) && !heroi->colideComBordas(*fase1_[1]))||(heroi->getPosC()== 116 || heroi->getPosC()== 120 )) ){
            heroi -> moveRight(6);

        }else if(ent == "a" && ((!heroi->colideComBordas(*fase1_[0])&& !heroi->colideComBordas(*fase1_[4]) || heroi->getPosC() == 88|| heroi->getPosC() ==92)) ){
            heroi->moveLeft(6);


        }else if(ent == "s" && (!heroi->colideComBordas(*fase1_[3]) && !heroi->colideComBordas(*fase1_[2])|| (heroi->getPosC()<156 && heroi->getPosC()>116 && heroi->getPosL()<27 )||heroi->colideComBordas(*fase1_[3])&&heroi->getPosL()==22)){
            heroi->moveDown(6);
        }
        //logica movimentaação da aranha
        if(!aranha->colideComBordas(*bau) && aranha->get_objetivo() == false  && heroi->atacar()<=10)
            aranha->moveRight(aranha->getVelocidade());

        if(heroi->colideComBordas(*chave)){
            heroi->pegarChave();
            chave->desativarObj();
        }
        if(heroi->getPosL() >= 62  && heroi->getchave() == true && ent == "q"){
            fissura->desativarObj();
        }
        else{
           if(aranha->get_objetivo()==true){
                if(aranha->getPosC()+5 < heroi->getPosC() && aranha->getPosC()-5 < heroi->getPosC())
                    aranha->moveRight(5);
                    
                else if(aranha->getPosC()+5 > heroi->getPosC() && aranha->getPosC()-5 > heroi->getPosC())
                    aranha->moveLeft(5);
                else if(aranha->getPosL()<heroi->getPosL())
                    aranha->moveDown(aranha->getVelocidade());
                else if(aranha->getPosL()>heroi->getPosL())
                    aranha->moveUp(aranha->getVelocidade());
                
            }}
        //logica de combate da aranha
        if(heroi->info_vivo()==true)
            if(heroi->colideComBordas(*aranha)){

                heroi->tirarvida(aranha->get_ataque());
                aranha->moveTo(5,aranha->getPosC());
            }
        if(heroi->info_vivo()== false){
            heroi->desativarObj();
            exit(1);}
            
            
       

        //aqui fica a logica da fase 1 part1
        if(heroi->colideComBordas(*tapete) && !heroi->colideComBordas(*Caveira_Espada[2])){
       
                if(!Caveira_Espada[2]->colideComBordas(*tapete)){
            
                    
                   
                    if(!Caveira_Espada[2]->colideComBordas(*tapete)){
                        Caveira_Espada[2]->moveLeft(5);
                    }
            
        }

    }   //aqui é a logica da fase de combate
        if(Caveira_Espada[2]->info_vivo()==true && heroi->info_vivo()==true && heroi->colideComBordas(*Caveira_Espada[2])){//aqui em cima
         
                Caveira_Espada[2]->Tirar_Vida(10);
                heroi->tirarvida(5);//aqui no meio
                if(aranha->colideComBordas(*heroi))
                    heroi->tirarvida(30);
                
                if(Caveira_Espada[2]->info_vivo()==false ){
                    Caveira_Espada[2]->desativarObj();
                    }
                if(heroi->info_vivo()==false){//aqui embaixo
                    heroi->desativarObj();
                    
                
                
            } }   
            //logica de pegar caixa

            if(heroi->colideComBordas(*bau)){
                heroi->set_Ataque(20);
                aranha->set_objetivo();
                aranha->Set_velocidade(2);
                bau->desativarObj();
            }
            if(aranha->colideComBordas(*bau)){
                aranha->Set_velocidade(7);
                aranha->set_ataque();
                aranha->set_objetivo();
                bau->desativarObj();
            }
        
        //fim da part1
        //Inicio da part2
        //momentação do inimigo
        if((heroi->getPosL()==tapete2->getPosL()||heroi->colideComBordas(*tapete2)) && Caveira_Espada[3]->info_vivo()==true && Caveira_Espada[4]->info_vivo()==true){
            if(!Caveira_Espada[3]->colideComBordas(*tapete2)||!Caveira_Espada[4]->colideComBordas(*tapete2)){
                if(!Caveira_Espada[3]->colideComBordas(*tapete2)){
                    Caveira_Espada[3]->moveUp(3);
                }
                if(!Caveira_Espada[4]->colideComBordas(*tapete2)){
               
                    Caveira_Espada[4]->moveUp(3);
                }
             
            }

        }
        //logica de combate do inimigo
        if((Caveira_Espada[3]->info_vivo()==true || Caveira_Espada[4]->info_vivo()== true) && heroi->info_vivo()==true && heroi->colideComBordas(*tapete2)){
                
                
               
                if(aranha->colideComBordas(*heroi))
                    heroi->tirarvida(30);

                Caveira_Espada[3]->Tirar_Vida(10);
                Caveira_Espada[4]->Tirar_Vida(10);
                heroi->tirarvida(5);
                if(Caveira_Espada[3]->info_vivo()==false){
                    Caveira_Espada[3]->desativarObj();
                    
                }
                if(Caveira_Espada[4]->info_vivo()==false){
                    Caveira_Espada[4]->desativarObj();

                }
                if(heroi->info_vivo() == false){
                    heroi->desativarObj();
                    
                }
                if((Caveira_Espada[4]->info_vivo()==false && Caveira_Espada[3]->info_vivo()==false)){
                    
                }

                
                
        //    } 
        }   
        //fim part2
        //Inicio da part3
        //logica de movimentaçãao dos personagens
        if(heroi->colideComBordas(*tapete3) && Caveira_Espada[0]->info_vivo()== true && Caveira_Espada[1]->info_vivo()==true && Caveira_Espada[5]->info_vivo()==true){
            Caveira_Espada[0]->info_vivo();
            
            if(!Caveira_Espada[0]->colideComBordas(*tapete3)||!Caveira_Espada[1]->colideComBordas(*tapete3)||!Caveira_Espada[5]->colideComBordas(*tapete3)){
                if(!Caveira_Espada[0]->colideComBordas(*tapete3)){
                    
                    Caveira_Espada[0]->moveRight(4);
                }
                if(!Caveira_Espada[1]->colideComBordas(*tapete3)){
                    Caveira_Espada[1]->moveRight(3);
                }
                if(!Caveira_Espada[5]->colideComBordas(*tapete3)){
                    Caveira_Espada[5]->moveRight(3);
                }
              
                }
        }
        //logica de combate
         //logica de combate do inimigo espada
         if(ent == "e" &&(Caveira_Espada[0]->info_vivo()==true || Caveira_Espada[1]->info_vivo()== true ||  Caveira_Espada[5]->info_vivo()== true) && heroi->info_vivo()==true && heroi->colideComBordas(*tapete3)){
           
            
                    Caveira_Espada[0]->Tirar_Vida(5);
                    Caveira_Espada[1]->Tirar_Vida(5);
                    Caveira_Espada[5]->Tirar_Vida(5);
                    heroi->tirarvida(5);
                if(aranha->colideComBordas(*heroi))
                    heroi->tirarvida(30);
                if(!flecha->colideComBordas(*heroi))
                    flecha->moveRight(10);
                if(Caveira_Espada[0]->info_vivo()==false){
                    Caveira_Espada[0]->desativarObj();
                    
                }

                if(Caveira_Espada[1]->info_vivo()==false){
                    Caveira_Espada[1]->desativarObj();

                }
                if(Caveira_Espada[5]->info_vivo()==false){
                    Caveira_Espada[5]->desativarObj();

                }
                if(heroi->info_vivo() == false){
                    heroi->desativarObj();
                    
                }
                if(Caveira_Espada[0]->info_vivo()==false && Caveira_Espada[1]->info_vivo()==false && Caveira_Espada[5]->info_vivo()==false){
                    flecha->desativarObj();
                    
                }
            

                
                
        }   
            //logica de combate da caveira arqueira
            
            
            
            
            if((Caveira_Arqueira[0]->info_vivo()==true) && heroi->info_vivo()==true && Caveira_Espada[0]->info_vivo()==false){
                    if(estado == true){
                        flecha->ativarObj();
                        flecha->moveTo(heroi->getPosL(),Caveira_Arqueira[0]->getPosC());
                        estado = false;
                    }        
                    
                    flecha->moveRight(7);
                    if(ent == "e" && heroi->colideComBordas(*Caveira_Arqueira[0])){
                        Caveira_Arqueira[0]->Tirar_Vida(5);

                    }
                    if(flecha->colideComBordas(*heroi)){
                        heroi->tirarvida(5);

                        estado=true;
                        flecha->desativarObj();
                    }
                    else if(flecha->getPosC()>heroi->getPosC()){
                        std::cout<<"tick3";                        
                        estado = true;
                        flecha->desativarObj();

                    }
                    if(heroi->info_vivo() == false){
                        heroi->desativarObj();
                        
                    }
                    if(Caveira_Arqueira[0]->info_vivo()==false){
                        Caveira_Arqueira[0]->desativarObj();
                        
                    }
                
    
                    
                    
            
                }
            
        //fim part 3

        



        //padrão
        update();
        draw(screen);//desenha as coisas
		system("clear");
		show(screen);


    }
    return Fase::END_GAME;





}
bool FaseLevel1::colideComBloco() const
{
	for (auto it = colisoes.begin() ; it != colisoes.end() ; ++it)
		if (heroi->colideCom(**it)) {
			return true;
		}
	
	return false;
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