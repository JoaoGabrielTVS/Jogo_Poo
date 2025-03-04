#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "../ASCII_Engine/Fase.hpp"
#include <string>
#include <list>
#include "Inimigo_comum.hpp"
#include "Heroi.hpp"
#include "Inimigo_Arco.hpp"
#include "Aranha.hpp"
class FaseLevel1:public Fase{
    public:
        FaseLevel1(std::string name, const Sprite &bkg):Fase(name, bkg){}
        FaseLevel1(std::string name, const SpriteAnimado &bkg):Fase(name, bkg){}
        virtual ~FaseLevel1(){}
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);
        
        //bool colideComBloco() const;



    private:
        //Inimigo *Espadeiro[2];
        Heroi *heroi;
        Inimigo_comum *Caveira_Espada[6];
        ObjetoDeJogo *chave;
        Inimigo_Arco *Caveira_Arqueira[3];
        Aranha *aranha;
        ObjetoDeJogo *bau;
        ObjetoDeJogo *tapete;
        ObjetoDeJogo *tapete2;
        ObjetoDeJogo *tapete3;
        ObjetoDeJogo *flecha;
        ObjetoDeJogo *coracao[10];
};



#endif //FASELEVEL1_HPP