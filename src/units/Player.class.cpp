// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Player.class.cpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Player.class.hpp"

/*
** key event handlers
*/
void on_player_left_key(const int, void *player_ptr)
{
    static_cast<Player *>(player_ptr)->direction = LEFT;
}

void on_player_right_key(const int, void *player_ptr)
{
    static_cast<Player *>(player_ptr)->direction = RIGHT;
}

void on_player_top_key(const int, void *player_ptr)
{
    static_cast<Player *>(player_ptr)->direction = TOP;
}

void on_player_bottom_key(const int, void *player_ptr)
{
    static_cast<Player *>(player_ptr)->direction = BOTTOM;
}


/*
** constructor
*/
Player::Player(const int new_x, const int new_y):
    Unit(new_x, new_y, PLAYER_SPRITE)
{
	DEBUG("Player constructed (default).");
}


/*
** destructor
*/
Player::~Player(void)
{
	DEBUG("Player destructed.");
}


/*
** public
*/
void            Player::play_turn(void)
{
    this->move(this->direction);
    //TODO: add diag movement

    // this->direction = NO_DIRECTION;

    //TODO: shoot and stuffs
}
