#include <iostream>

using namespace std;

class Mage{
protected:
    int power,hp;
    string name;
public:
    Mage(string Bname,int Bhp,int Bpower){
        name = Bname;
        hp = Bhp;
        power = Bpower;
    }

    int Damage(){
        return power;
    }

    void GetDamage(int Value){
        hp -= Value;
        cout << "A " << name <<" le queda: " << hp << endl;
    }

    int GetHP(){
        return hp;
    }
};

class IceMage : public Mage{
public:
    IceMage(string Bname,int Bhp,int Bpower) : Mage( Bname, Bhp, Bpower){
        hp = Bhp + 10;
        power = Bpower - 10; 
    }
};

class FireMage : public Mage
{
public:
    FireMage(string Bname,int Bhp,int Bpower): Mage( Bname, Bhp, Bpower){
        hp = Bhp - 10;
        power = Bpower + 10;
    }
};

int main()
{
    Mage* CurrentMage;
    IceMage Caput("Caput",100,150);  
    FireMage Junior("Junior",100,150);

    CurrentMage = &Caput;
    CurrentMage->GetDamage(10);

    CurrentMage = &Junior;
    CurrentMage->GetDamage(10);

    return 0;
    
}