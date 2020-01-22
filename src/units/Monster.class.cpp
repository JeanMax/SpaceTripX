// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Monster.class.cpp                                         (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Monster.class.hpp"


/*
** constructor
*/
Monster::Monster(const int new_x, const int new_y):
    Unit(new_x, new_y, MONSTER_SPRITE)
{
	DEBUG("Monster constructed (default).");

    this->direction = BOTTOM;
}


/*
** destructor
*/
Monster::~Monster(void)
{
	DEBUG("Monster destructed.");
}


/*
** public
*/
void            Monster::play_turn(void)
{
    this->move(this->direction);
}
