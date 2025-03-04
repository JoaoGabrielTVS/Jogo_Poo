#ifndef INIMIGO_ESPADA_HPP
#define INIMIGO_ESPADA_HPP  // <-- Corrigido
#include <vector>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Inimigo.hpp"

class Inimigo_comum: public Inimigo
{
    public:
        Inimigo_comum(const ObjetoDeJogo &obj , int life =60, int velAtaque =5):Inimigo(obj), life(life), velAtaque(velAtaque), contAtaque(velAtaque){}
        virtual ~Inimigo_comum(){}
        bool info_vivo() const {return life != 0;}
     
        void Tirar_Vida(int ataque) override{
            life = (life - ataque >= 0)?(life - ataque) :0;

        }
    protected:
        int life;
        int velAtaque, contAtaque;

};


#endif // INIMIGO_ESPADA_HPP