#ifndef INIMIGO_Arco_HPP
#define INIMIGO_Arco_HPP  // <-- Corrigido
#include <vector>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Inimigo_comum.hpp"

class Inimigo_Arco: public Inimigo_comum
{
    public:
        Inimigo_Arco(const ObjetoDeJogo &obj , int life =30, int velAtaque =3):Inimigo_comum(obj, life , velAtaque){}
        virtual ~Inimigo_Arco(){}
        void Atirar(){
           
        }
        
        void Tirar_Vida(int ataque) override{
            life = (life - ataque >= 0)?(life - ataque) :0;

        }
        



};


#endif // INIMIGO_Arco_HPP