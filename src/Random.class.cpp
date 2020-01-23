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
Random::Random(const int min, const int max):
    _mt(_init_seed()),
    _dist(std::uniform_int_distribution<int>(min, max))
{
	DEBUG("Random constructed (default).");
}


/*
** destructor
*/
Random::~Random(void)
{
	DEBUG("Random destructed.");
}


/*
** private
*/
std::mt19937    Random::_init_seed(void)
{
    std::random_device rd;

    return std::mt19937(rd());
}


/*
** public
*/
int             Random::generate(void)
{
    return this->_dist(this->_mt);
}
