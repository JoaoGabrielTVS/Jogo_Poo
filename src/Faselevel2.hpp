#ifndef TRANSICAO_HPP
#define TRANSICAO_HPP
#include "Dragao.hpp"
#include "../ASCII_Engine/Fase.hpp"
#include <string>
#include <list>
#include "Inimigo_comum.hpp"
#include "Heroi.hpp"
#include "Inimigo_Arco.hpp"
#include "Aranha.hpp"

class Faselevel2:public Fase{
    public:
    Faselevel2(std::string name, const Sprite &bkg):Fase(name, bkg){}
    Faselevel2(std::string name, const SpriteAnimado &bkg):Fase(name, bkg){}
        bool colideComBloco() const;

        virtual ~Faselevel2(){}
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);
        void incrementar_counter(){
            counter++;
        }
        void reiniciar_counter(){
            counter = 0;
        }
        int get_counter(){
            return counter;
        }
        //bool colideComBloco() const;



    private:
    
    Heroi *heroi;
    Aranha *aranha;
    ObjetoDeJogo *bau;
    ObjetoDeJogo *fase2_[5];
    ObjetoDeJogo *fissura;
    ObjetoDeJogo *coracao;
    ObjetoDeJogo *vida;
    Dragao *dragao;
    ObjetoDeJogo *bola;
    int counter=0;
    std::list<ObjetoDeJogo*> colisoes;

};



#endif //TRANSICAO_HPP