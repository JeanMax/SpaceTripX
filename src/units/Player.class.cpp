// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Player.class.cpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Player.class.hpp"


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
