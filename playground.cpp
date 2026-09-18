#include <iostream>
#include <memory>
#include <cstdlib>
#include <string>




int nextID = 0;

class Player {

    
    private: 
        int ID;
        std::string Name;
    
    public:

        std::string getName()
        {
            return Name;
        }

        void setName(std::string name)
        {
            Name = name;
        }
    
    Player(std::string name) 
    {
        ID = ++nextID;
        Name = name;
        std::cout<<"Making: "<<name<<" "<<ID<<'\n';
    }

    Player(const Player& Original)
    :
    ID{++nextID},
    Name{Original.Name}
    {
        std::cout<<"Copying player "<<Original.ID<<" to "<<ID<<'\n';        
    }



};

int main() {

    Player p1("sex");

    Player p2 = p1;

    std::cout<<p2.getName();
    
}