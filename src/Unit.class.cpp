// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Unit.class.cpp                                            (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Unit.class.hpp"


/*
** constructor
*/
Unit::Unit(int new_x, int new_y, int new_w, int new_h):
    Point(new_x, new_y)
{
	DEBUG("Unit constructed (default).");

    this->w = new_w;
    this->h = new_h;
}

Unit::Unit(Unit const &copy)
{
	DEBUG("Unit constructed (copy).");

    this->x = copy.x;
    this->y = copy.y;
    this->w = copy.w;
    this->h = copy.h;
}


/*
** destructor
*/
Unit::~Unit(void)
{
	DEBUG("Unit destructed.");
}


/*
** operator overload
*/
Unit           &Unit::operator=(Unit const &copy)
{
	DEBUG("Unit operator= called.");

    this->x = copy.x;
    this->y = copy.y;
    this->w = copy.w;
    this->h = copy.h;

	return *this;
}


/*
** public
*/
Unit            &Unit::move(enum direction direction)
{
    *this += g_base_vectors[direction];

    return *this;
}


/*
** getter/setter
*/
Unit           &Unit::set_coord(int new_x, int new_y)
{
    this->x = new_x;
    this->y = new_y;

	return *this;
}

Unit           &Unit::set_size(int new_w, int new_h)
{
    this->w = new_w;
    this->h = new_h;

	return *this;
}

Unit           &Unit::set_dim(int new_x, int new_y, int new_w, int new_h)
{
    this->x = new_x;
    this->y = new_y;
    this->w = new_w;
    this->h = new_h;

    return *this;
}
