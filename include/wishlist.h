#if !defined  _WISHLIST
#define _WISHLIST
#include <vector>
#include <iostream>

using namespace std;

class Game {
private:
    int cod;
    string name;
    float price;


public:
    Game (int cod, float price, string name) : cod(cod), price(price), name(name);
    virtual ~Game();
    void setPrice(float price);
    float getPrice();

};

class Wishlist {
private:
    vector<Game> gamesList;

public:
    void addList(Game game);
    Wishlist();
    virtual ~Wishlist();S
};


#endif
