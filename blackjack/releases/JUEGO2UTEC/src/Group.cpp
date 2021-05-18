/* 
*   blackjack game - Group class implementation
*
*/
#include "../include/Player.h"
#include "../include/Group.h"

#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

bool Group::isInGroup(Player player)
{
    for(Player groupPlayer: players)
    {
        if(groupPlayer.getName() == player.getName())
        {
            return true;
        }
    }
    return false;
}

int Group::searchByName(string nameQueryPlayer)
{
    for(int i=0; i<players.size(); i++)
    {
        if(players[i].getName() == nameQueryPlayer)
            return i;
    }
    return -1;
}

Player* Group::getPPlayerByName(string nameQueryPlayer)
{
    int idxQueryPlayer = this->searchByName(nameQueryPlayer);

    if(idxQueryPlayer >= 0)
    {
        return &players[idxQueryPlayer];
    }
    return nullptr;
}

bool Group::allDead()
{
    for(Player bjPlayer: players)
    {
        if(bjPlayer.getAlive())
            return false;
    }
    return true;
}

int Group::getIdxPlayer(Player player)
{
    if(this->isInGroup(player))
    {
        for(int i=0; i<players.size(); i++)
        {
            if(players[i].getName() == player.getName())
                return i;
        }
    }
    return -1;
}

Player* Group::getPointerPlayer(Player queryPlayer)
{
    if(this->isInGroup(queryPlayer))
    {
        int idxQueryPlayer = this->getIdxPlayer(queryPlayer);
        return &players[idxQueryPlayer];
    }
    return nullptr;
}


void Group::addPlayer(Player new_player)
{
    players.push_back(new_player);
}

void Group::delPlayer(Player del_player)
{   
    int idx_del_player = this->getIdxPlayer(del_player);
    if(idx_del_player >= 0)
        players.erase(players.begin()+idx_del_player);
}

void Group::listPlayers()
{
    for(Player player: players)
    {
        string name_player = player.getName();
        double cash_player = player.getCash(); 

        cout    << name_player
                << "\t" << cash_player << endl;
    }
}

/* LINUX
#include <thread>
#include <chrono>
*/

void Group::showStatistics()
{
    for(Player bjPlayer: players)
    {
        sleep(1);
        //std::this_thread::sleep_for (std::chrono::seconds(1));
        bjPlayer.getStatistics();
    }
			
}

void Group::listLenderPlayers(string beggarPlayerName)
{
    for(Player bjPlayer: players)
    {
        if(bjPlayer.getName() != beggarPlayerName)
        {
            double currentCash = bjPlayer.getCash() - bjPlayer.getBet();
            cout << bjPlayer.getName() << "\t" << currentCash << endl;
        }
    }
}