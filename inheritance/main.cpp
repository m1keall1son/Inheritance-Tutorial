//
//  main.cpp
//  inheritance
//
//  Created by Mike Allison on 10/2/14.
//  Copyright (c) 2014 Mike Allison. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>


using AnimalRef = std::shared_ptr<class Animal>;

class Animal {
public:
    
    virtual ~Animal(){  }
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void talk(){
        std::cout << "Animal sound: " << std::endl;
    };
    
    
};

using DuckRef = std::shared_ptr<class Duck>;

class Duck : public Animal {
public:
    
    static DuckRef create(){ return DuckRef( new Duck() ); }
    
    ~Duck(){}
    void eat() override {}
    void sleep() override {}
    void talk() override {
        Animal::talk();
        std::cout<< "Quack" << std::endl;
    }
    
private:
    
    Duck(){}
    
    friend class DuckFactory;
    
};

using WolfRef = std::shared_ptr<class Wolf>;

class Wolf : public Animal {
    
public:
    
    static WolfRef create(){ return WolfRef( new Wolf() ); }
    
    ~Wolf(){ }
    void eat(){}
    void sleep(){}
    void talk() {
        Animal::talk();
        std::cout<< "Howl" << std::endl;
    }
    void dig(){}
    
private:
    
    Wolf(){}
    
    friend class WolfFactory;
    
};



class DuckFactory  {
public:
   static DuckRef create( /*  different stuff here  */ ){ return DuckRef( new Duck() ); }
    
};


class WolfFactory  {
public:
   static WolfRef create(){ return WolfRef( new Wolf() ); }
    
};


std::vector<AnimalRef> mAnimals;

int main(int argc, const char * argv[])
{

    mAnimals.push_back( Duck::create() );
    mAnimals.push_back( Wolf::create() );
    
    AnimalRef a = mAnimals[0];
    
    for(auto& animal : mAnimals){
        animal->talk();
    }
    
    return 0;
}

