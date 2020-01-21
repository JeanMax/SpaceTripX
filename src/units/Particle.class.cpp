// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Particle.class.cpp                                        (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Particle.class.hpp"


/*
** constructor
*/
Particle::Particle(const int new_x, const int new_y):
    Unit(new_x, new_y, PARTICLE_SPRITE)
{
	DEBUG("Particle constructed (default).");

    this->direction = BOTTOM;
}


/*
** destructor
*/
Particle::~Particle(void)
{
	DEBUG("Particle destructed.");
}


/*
** public
*/
void            Particle::play_turn(void)
{
    this->move(this->direction);

    //TODO: move to top if necessary
}
