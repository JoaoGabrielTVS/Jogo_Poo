#ifndef HEROI_HPP
#define HEROI_HPP
#include <vector>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Heroi :public ObjetoDeJogo
{
public:
    Heroi(const ObjetoDeJogo &obj , int life = 200):ObjetoDeJogo(obj),life(life), bomba(false),ataque(10){}
    virtual ~Heroi()	{}
    bool info_vivo() const {return life != 0;}
    int getLife() const {return life;}
    void tirarvida(int ataque){
        life = (life - ataque >= 0)?(life - ataque) : 0;

    }
    void setvel (int vel){
        this->vel = vel;
    }
    void set_Ataque(int Bonus){
        ataque +=Bonus;
    }
    int getvel()const{
        return vel;
    }
    int atacar() const {return ataque;}

    void pegarChave(){bomba =true;}
    bool getchave(){return bomba;}


private: 
    int life;
    bool bomba;
    int vel;
    int ataque;

    //std::vector <ObjetoDeJogo> Inventario;

};




#endif //HEROI_HPP