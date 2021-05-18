#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include<string>
#include<vector>

#ifndef INCLUDE_CARD_H_
#include "Card.h"
#endif  /*INCLUDE_CARD_H_*/

#ifndef INCLUDE_HAND_H_
#include "Hand.h"
#endif  /*INCLUDE_HAND_H_*/

#ifndef INCLUDE_DECK_H_
#include "Deck.h"
#endif /*INCLUDE_DECK_H_*/

#ifndef INCLUDE_PLAYER_H_
#include "Player.h"
#endif /*INCLUDE_PLAYER_H_*/

class Group
{
private:
    vector<Player> players;
public:
    Group(){};

    vector<Player> getPlayers(){return players;}
    bool isInGroup(Player player);    // return true if player is in Group
    bool allDead();

    Player* getPointerPlayer(Player queryPlayer);
    
    // return the index if the player exist(searched by name)
    // otherwise return -1
    int searchByName(string nameQueryPlayer);
    // return a pointer to a player(searched by name)
    // otherwise return nullptr
    Player* getPPlayerByName(string nameQueryPlayer);

    // return a int great than 0 if player is in group otherwise return -1
    int getSize(){return players.size();}
    int getIdxPlayer(Player player);    
    
    void addPlayer(Player new_player);  // add a new player to group
    void delPlayer(Player del_player);  // delete a player of group (if it exist)
    
    void listPlayers();
    void listLenderPlayers(string beggarPlayerName);
    void showStatistics();
    vector<Player>* getPointerPlayers(){return &players;}
    //~Group();
};


#endif