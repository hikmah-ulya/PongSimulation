#include<iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>
#include "Player.h"
#include "Score.h"
using namespace std;

Score score(0, 0);
mutex m;

void randomFirstTurn(int* player)
{

    int* j = new int;
    srand((int)j);
    delete j;
    *player = rand() % 2;
}

void PLayerHitRandoms(Player* player, bool* isOver)
{

    int* j = new int;
    m.lock();

    srand((int)j);
    delete j;
    player->SetHits(rand() % 101);
    m.unlock();

    //tampilan
    cout << "Hits (Point) : " << player->GetHits();
    if (player->GetPleyer() == 0) {
        cout << " Player X ";
    }
    else {
        cout << " Player Y ";
    }

    if (player->GetHits() <= 50)
    {
        if (player->GetPleyer() == 0)
        {
            cout << "Player Y =  1 Skor" << endl;
            score.AddSkorY();
        }
        else
        {
            cout << "Player X = 1 Skor" << endl;
            score.AddSkorX();
        }
        cout << "Lost" << endl;

        *isOver = true;
    }
    else
    {
        cout << "Goal" << endl;
    }

    this_thread::sleep_for(chrono::seconds(1));
}

int main()
{
    int a;
        int round = 1;
        Score s;
        srand(time(0));
        a = rand() % 2; //randoms first player

        Player player1(a);
        Player player2 = player1; //clone
    
    int play = 1;
        while (score.skorX() < 10 && score.skorY() < 10)
        {
            int play;
            thread RandomFirst(randomFirstTurn, &play);
            RandomFirst.join();
            bool roundOver = false;

            cout << "Match : " << play << endl;
            while (roundOver == false) {
                if (play == 0)
                {
                    cout << "Player X Mendapat Giliran Pertama" << endl;

                    thread playerXThread(PLayerHitRandoms, &player1, &roundOver);
                    playerXThread.join();

                    if (roundOver == true) {
                        play++;
                        break;
                    }

                    thread playerYThread(PLayerHitRandoms, &player2, &roundOver);
                    playerYThread.join();

                    if (roundOver == true) {
                        play++;
                        break;
                    }
                }
                else if (play == 1)
                {
                    cout << "Player Y Mendapat Giliran Pertama" << endl;

                    thread playerYThread(PLayerHitRandoms, &player2, &roundOver);
                    playerYThread.join();

                    if (roundOver == true)
                    {
                        play++;
                        break;
                    }

                    thread playerXThread(PLayerHitRandoms, &player1, &roundOver);
                    playerXThread.join();

                    if (roundOver == true) {
                        play++;
                        break;
                    }
                }
            }
        }

        cout << "\nHsil" << endl;
        if (score.skorX() >= 10) {
            cout << "Player X Menang :  " << endl << score.skorX() << "-" << score.skorY() << endl;
        }
        else {
            cout << "Player Y Menang :  " <<endl  << score.skorY() << "-" << score.skorX() << endl;
        }

        return 0;
}
