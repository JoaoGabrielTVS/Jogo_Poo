#ifndef Inimigo_HPP
#define Inimigo_HPP  // <-- Corrigido
#include <vector>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"


class Inimigo:public ObjetoDeJogo
{
    public:
        Inimigo(const ObjetoDeJogo &obj , int velAtaque =3):ObjetoDeJogo(obj), velAtaque(velAtaque){}
        virtual ~Inimigo(){}
        virtual void Tirar_Vida(int ataque){
            
        }
        
    protected:
        int velAtaque;


};


#endif // Inimigo_HPP