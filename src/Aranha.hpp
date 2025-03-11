#ifndef Aranha_HPP
#define Aranha_HPP  // <-- Corrigido
#include <vector>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Inimigo_comum.hpp"
#include "Inimigo.hpp"
#include <random>
class Aranha: public Inimigo
{
    public:
        Aranha(const ObjetoDeJogo &obj , int velAtaque =3):Inimigo(obj , velAtaque),velocidade(3),objetivo(false),ataque(30){
            std::random_device rd;  
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1, 100);
            if(dist(gen)>80){
            objetivo = !objetivo;}
        }
        virtual ~Aranha(){
         

        }
        void pensando(){
            
        }


        int get_ataque(){
            return ataque; 
        }
        void Set_velocidade(int bonus){
            this->velocidade += bonus;
        }    
        int getVelocidade()const{
            return this->velocidade;
        }
        void set_objetivo(){
            objetivo = !objetivo;
            
            
        }
        void set_ataque(){
            this->ataque = 1000;
        }
        bool get_objetivo(){
            return objetivo;
        }
    private:
    int velocidade;
    bool objetivo;
    int ataque;



};


#endif // Aranha_HPP