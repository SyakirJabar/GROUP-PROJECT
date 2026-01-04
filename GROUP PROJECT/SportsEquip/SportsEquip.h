//SportsEquip.h
//base (abstract) class

#include <string>

typedef std::string str;

class SportsEquip
{
public:
    ~SportsEquip();     //destructor

    //setters (virtual)
    virtual void setName(const str&) = 0;
    virtual void setCateg(const str&) = 0;  //category of sports equipment
    virtual void setGoodQ(const int&) = 0;  //quantity of equipments not broken or lost
    virtual void setBrokenQ(const int&) = 0;
    virtual void setLostQ(const int&) = 0;

    //getters (virtual)
    //does not modify object representation
    virtual str getName() const = 0;
    virtual str setCateg() const = 0;
    virtual int setGoodQ() const = 0;  
    virtual int setBrokenQ() const = 0;
    virtual int setLostQ() const = 0;
};  
