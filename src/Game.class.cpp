// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Game.class.cpp                                            (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"


/*
** constructor
*/
Game::Game(const int n_players) : _n_players(n_players)
{
    int i, offset;

	DEBUG("Game constructed (default).");

    for (i = n_players; i < MAX_PLAYERS; i++) {
        this->players[i].kill();
    }

    offset = GAME_WIDTH / (n_players + 1) - 2;
    for (i = 0; i < n_players; i++) {
        this->players[i].set_coord(
            offset * (i + 1) + (i + 1),
            GAME_HEIGHT - 3
        );
    }
}


/*
** destructor
*/
Game::~Game(void)
{
	DEBUG("Game destructed.");
}


/*
** public
*/
void            Game::play_turn(void)
{
    Point prev_pos;

    for (int i = 0; i < this->_n_players; i++) {
        if (!this->players[i].is_alive()) {
            continue;
        }

        prev_pos = this->players[i];
        this->players[i].play_turn();
        if (this->players[i].outside(this->_map)) {
            this->players[i].set_coord(prev_pos.x, prev_pos.y);
        }
    }
}

bool            Game::game_over(void) const
{
    for (int i = 0; i < this->_n_players; i++) {
        if (this->players[i].is_alive()) {
            return false;
        }
    }

    return true;
}
