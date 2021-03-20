//
//  Score.h
//  labwork2
//
//  Created by hilyah syahidah on 20/03/21.
//

#ifndef Score_h
#define Score_h
class Score
{
private:
    int SkorplayerX = 0;
    int SkorplayerY = 0;

public:
    Score(int x, int y)
    {
        SkorplayerX = x;
        SkorplayerY = y;
    }

    int skorX()
    {
        return SkorplayerX;
    }

    int skorY()
    {
        return SkorplayerY;
    }

    void SetSkor(int x, int y)
    {
        SkorplayerX = x;
        SkorplayerY = y;
    }

    void AddSkorX()
    {
        SkorplayerX++;
    }

    void AddSkorY()
    {
        SkorplayerY++;
    }

};

#endif /* Score_h */
