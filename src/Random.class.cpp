// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Random.class.cpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Random.class.hpp"


/*
** constructor
*/
Random::Random(const int min, const int max)
{
	DEBUG("Random constructed (default).");

    std::random_device rd;
    this->mt = std::mt19937(rd());
    this->dist = std::uniform_int_distribution<int>(min, max);
}


/*
** destructor
*/
Random::~Random(void)
{
	DEBUG("Random destructed.");
}


/*
** public
*/
int             Random::generate(void)
{
    return this->dist(mt);
}
