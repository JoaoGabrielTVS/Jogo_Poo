#include "FaseLevel1.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

void FaseLevel1::init(){
    tapete = new ObjetoDeJogo("Tapete", Sprite("rsc/tapete.img", COR::AMARELA),6,120);
    objs.push_back(tapete);
    
    tapete2 = new ObjetoDeJogo("Tapete2", Sprite("rsc/tapete_deitado.img", COR::AMARELA),23,140);
    objs.push_back(tapete2);
    tapete3 = new ObjetoDeJogo("Tapete3", Sprite("rsc/tapete.img", COR::AMARELA),26,120);
    objs.push_back(tapete3);
    aranha = new Aranha(ObjetoDeJogo("Aranha", SpriteAnimado("rsc/Meu_Aranha.img",2),6,20));
   

    objs.push_back(aranha); 
    heroi = new Heroi(ObjetoDeJogo("Heroi", SpriteAnimado("rsc/Meu_Heroi.img",1,COR::CIANO),6,80));
    objs.push_back(heroi);
    
    Caveira_Espada[0] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),27,80));
    
    objs.push_back(Caveira_Espada[0]);
    
    Caveira_Espada[1] = new Inimigo_comum(ObjetoDeJogo("Inimigo_Da_Espada", SpriteAnimado("rsc/Caveira_Espadachim.img",1),26,60));
    objs.push_back(Caveira_Espada[1]);
    
    
    flecha = new ObjetoDeJogo("flecha", Sprite("rsc/flecha_esc.img", COR::AMARELA),30,29);
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
	
   

    chave = new ObjetoDeJogo("Chave",Sprite("rsc/Meu_chave.img",COR::AMARELA),30,10);
	objs.push_back(chave);
    bau = new ObjetoDeJogo("Bau", Sprite("rsc/Meu_bau.img",COR::MARROM_ESCURA),6,190);
    objs.push_back(bau);


    /*
    aranha = new ObjetoDeJogo("Aranha",SpriteAnimado("rsc/Meu_Aranha.img",1),3, 20);
    objs.push_back(aranha);
    */
    }

unsigned FaseLevel1::run(SpriteBuffer &screen)
{   
    std::string ent;
    draw(screen);
    system("clear");
    show(screen);

    while(true){
        getline(std::cin, ent);
        int posL = heroi->getPosL() , posC = heroi->getPosC();
        if(ent == "w"){
            heroi->moveUp(4);
        
        }else if(ent == "d"){
            heroi -> moveRight(4);

        }else if(ent == "a"){
            heroi->moveLeft(4);


        }else if(ent == "s"){
            heroi->moveDown(4);
        }
        //logica movimentaação da aranha
        if(!aranha->colideComBordas(*bau) && aranha->get_objetivo() == false  && heroi->atacar()<=10)
            aranha->moveRight(aranha->getVelocidade());
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
        std::cout<<heroi->getLife();
        //logica de combate da aranha
        if(heroi->info_vivo()==true)
            if(heroi->colideComBordas(*aranha))
                heroi->tirarvida(aranha->get_ataque());
                
        if(heroi->info_vivo()== false){
            heroi->desativarObj();
            std::cout<<"entrou aqui";
            exit(1);}
            
            
       

        //aqui fica a logica da fase 1 part1
        if(heroi->colideComBordas(*tapete) && Caveira_Espada[2]->info_vivo()==true){
       
                while(!Caveira_Espada[2]->colideComBordas(*tapete)){
            
                    
                    std::this_thread::sleep_for(std::chrono::milliseconds(400));

                    update();
                    draw(screen);//desenha as coisas
                    system("clear");
                    show(screen);
                    if(!Caveira_Espada[2]->colideComBordas(*tapete)){
                        Caveira_Espada[2]->moveLeft(3);
                    }
            
        }

    }   //aqui é a logica da fase de combate
        if(Caveira_Espada[2]->info_vivo()==true && heroi->info_vivo()==true && heroi->colideComBordas(*tapete)){//aqui em cima
            while(Caveira_Espada[2]->info_vivo()==true && heroi->info_vivo()==true){
                
               
                
                std::this_thread::sleep_for(std::chrono::milliseconds(700));
                update();
                draw(screen);//desenha as coisas
                system("clear");
                show(screen);
                getline(std::cin, ent);
                
                
                Caveira_Espada[2]->Tirar_Vida(10);
                heroi->tirarvida(5);//aqui no meio
                if(aranha->colideComBordas(*heroi))
                    heroi->tirarvida(30);
                
                if(Caveira_Espada[2]->info_vivo()==false ){
                    Caveira_Espada[2]->desativarObj();
                    break;}
                if(heroi->info_vivo()==false){//aqui embaixo
                    heroi->desativarObj();
                    break;
                }
                
                
            } }   
            //logica de pegar caixa

            if(heroi->colideComBordas(*bau)){
                heroi->set_Ataque(20);
                aranha->set_objetivo();

                bau->desativarObj();
            }
            if(aranha->colideComBordas(*bau)){
                aranha->Set_velocidade(7);
                aranha->set_objetivo();
                bau->desativarObj();
            }
        
        //fim da part1
        //Inicio da part2
        //momentação do inimigo
        if(heroi->colideComBordas(*tapete2) && Caveira_Espada[3]->info_vivo()==true && Caveira_Espada[4]->info_vivo()==true){
            while(!Caveira_Espada[3]->colideComBordas(*tapete2)||!Caveira_Espada[4]->colideComBordas(*tapete2)){
                if(!Caveira_Espada[3]->colideComBordas(*tapete2)){
                    Caveira_Espada[3]->moveUp(3);
                }
                if(!Caveira_Espada[4]->colideComBordas(*tapete2)){
               
                    Caveira_Espada[4]->moveUp(3);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(400));
                update();
                draw(screen);//desenha as coisas
                system("clear");
                show(screen);
                Caveira_Espada[2]->moveLeft(3);
            
            }

        }
        //logica de combate do inimigo
        if((Caveira_Espada[3]->info_vivo()==true || Caveira_Espada[4]->info_vivo()== true) && heroi->info_vivo()==true && heroi->colideComBordas(*tapete2)){
            while((Caveira_Espada[3]->info_vivo()==true ||Caveira_Espada[4]->info_vivo()== true) && heroi->info_vivo()==true){
                
                
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                update();
                draw(screen);//desenha as coisas
                system("clear");
                show(screen);
                getline(std::cin, ent);
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
                    break;
                }
                if((Caveira_Espada[4]->info_vivo()==false && Caveira_Espada[3]->info_vivo()==false)){
                    break;
                }

                
                
            } }   
        //fim part2
        //Inicio da part3
        //logica de movimentaçãao dos personagens
        if(heroi->colideComBordas(*tapete3) && Caveira_Espada[0]->info_vivo()== true && Caveira_Espada[1]->info_vivo()==true && Caveira_Espada[5]->info_vivo()==true){
            Caveira_Espada[0]->info_vivo();
            
            while(!Caveira_Espada[0]->colideComBordas(*tapete3)||!Caveira_Espada[1]->colideComBordas(*tapete3)||!Caveira_Espada[5]->colideComBordas(*tapete3)){
                if(!Caveira_Espada[0]->colideComBordas(*tapete3)){
                    
                    Caveira_Espada[0]->moveRight(3);
                }
                if(!Caveira_Espada[1]->colideComBordas(*tapete3)){
                    Caveira_Espada[1]->moveRight(3);
                }
                if(!Caveira_Espada[5]->colideComBordas(*tapete3)){
                    Caveira_Espada[5]->moveRight(3);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(400));
                update();
                draw(screen);//desenha as coisas
                system("clear");
                show(screen);
                Caveira_Espada[2]->moveLeft(3);
            }
        }
        //logica de combate
         //logica de combate do inimigo espada
         if((Caveira_Espada[0]->info_vivo()==true || Caveira_Espada[1]->info_vivo()== true ||  Caveira_Espada[5]->info_vivo()== true) && heroi->info_vivo()==true && heroi->colideComBordas(*tapete3)){
            while((Caveira_Espada[1]->info_vivo()==true ||Caveira_Espada[0]->info_vivo()== true || Caveira_Espada[5]->info_vivo() == true) && heroi->info_vivo()==true){
                
                
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                update();
                draw(screen);//desenha as coisas
                system("clear");
                show(screen);
                getline(std::cin, ent);

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
                    break;
                }
                if(Caveira_Espada[0]->info_vivo()==false && Caveira_Espada[1]->info_vivo()==false && Caveira_Espada[5]->info_vivo()==false){
                    flecha->desativarObj();
                    break;
                }
            

                
                
            } }   
            //logica de combate da caveira arqueira
            
            
            
            
            if((Caveira_Arqueira[0]->info_vivo()==true) && heroi->info_vivo()==true && Caveira_Espada[0]->info_vivo()==false){
                bool estado = true;
                while((Caveira_Arqueira[0]->info_vivo()==true) && heroi->info_vivo()==true){
                   
        
                    
    
                    getline(std::cin, ent);
                    int posL = heroi->getPosL() , posC = heroi->getPosC();
                    if(ent == "w"){
                        heroi->moveUp(4);
                    
                    }else if(ent == "d"){
                        heroi -> moveRight(4);

                    }else if(ent == "a"){
                        heroi->moveLeft(4);


                    }else if(ent == "s"){
                        heroi->moveDown(4);
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(400));
                    update();
                    draw(screen);//desenha as coisas
                    system("clear");
                    show(screen);
                   
                    
                    if(estado == true){
                        flecha->ativarObj();
                        flecha->moveTo(heroi->getPosL(),Caveira_Arqueira[0]->getPosC());
                        estado = false;
                    }        
                    
                    
                    
    
                    flecha->moveRight(7);
                    if(aranha->get_objetivo() == false){
                        aranha->moveRight(aranha->getVelocidade());
                    }
                    if(aranha->colideComBordas(*heroi))
                        heroi->tirarvida(30);
                    if(heroi->colideComBordas(*Caveira_Arqueira[0])){
                        Caveira_Arqueira[0]->Tirar_Vida(5);

                    }
                    if(flecha->colideComBordas(*heroi)){
                        heroi->tirarvida(5);

                        estado=true;
                        flecha->desativarObj();
                    }
                    else if(flecha->getPosC()>heroi->getPosC()){
                        estado = true;
                        flecha->desativarObj();

                    }
                    if(heroi->info_vivo() == false){
                        heroi->desativarObj();
                        break;
                    }
                    if(Caveira_Arqueira[0]->info_vivo()==false){
                        Caveira_Arqueira[0]->desativarObj();
                        break;
                    }
                
    
                    
                    
                } }
            
        //fim part 3
        



        //padrão
        update();
        draw(screen);//desenha as coisas
		system("clear");
		show(screen);


    }
    return Fase::END_GAME;





}