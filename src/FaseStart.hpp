#ifndef FASESTART_HPP
#define FASESTART_HPP

#include "../ASCII_Engine/Fase.hpp"
#include <string>
#include <list>
#include "Inimigo_comum.hpp"
#include "Heroi.hpp"
#include "Inimigo_Arco.hpp"
#include "Aranha.hpp"
class FaseStart:public Fase{
    public:
        FaseStart(std::string name, const Sprite &bkg):Fase(name, bkg){}
        FaseStart(std::string name, const SpriteAnimado &bkg):Fase(name, bkg){}
        bool colideComBloco() const;

        virtual ~FaseStart(){}
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);
        
        //bool colideComBloco() const;



    private:
    ObjetoDeJogo *capa;
    ObjetoDeJogo *seta;
};



#endif //FASESTART _HPP