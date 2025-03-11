#ifndef Dragao_HPP
#define Dragao_HPP  // <-- Corrigido
#include <vector>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Inimigo_comum.hpp"
#include "Inimigo.hpp"
#include <random>
class Dragao: public Inimigo
{
    public:
        Dragao(const ObjetoDeJogo &obj , int velAtaque =3):Inimigo(obj , velAtaque),velocidade(1),objetivo(false),ataque(30){}
        virtual ~Dragao(){
          
        }

        
        


        int get_ataque(){
            return ataque; 
        }
        void tirar_vida(int vida){
            this->vida -= vida;
        }
        int get_vida() const{
            return vida;
        }
        
        
      
    private:
    int velocidade;
    bool objetivo;
    int ataque;
    int vida = 200;



};


#endif // Aranha_HPP