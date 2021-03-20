//
//  Player.h
//  labwork2
//
//  Created by hilyah syahidah on 20/03/21.
//


#ifndef Player_h
#define Player_h
#include <iostream>
using namespace std;

class Player{
  
private:
    float hits;
    enum player{playerX=1,playerY=0};
    string p;
    
public:
    float GetHits()
    {
        return hits;
    
    }
    void SetHits(float h)
    {
        hits = h;
    }

    player GetPleyer()
    {
        return player;
    }
    Player (int z)
    {
        if (z == playerY)
        {
            p = "\nPlayer Y";
        }
        else
        {
            p = "\nPlayerX";
        }
        hits=0;
    }
    Player(Player& z)
    {
        if (z.p == "\nPlayerY")
        {
            p = "\nPlayerZ";
        }
        else
        {
            p = "\nPlayerY";
        }
        hits= z.hits;
    }
 
};
#endif /* Player_h */
