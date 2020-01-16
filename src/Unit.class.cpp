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
Unit::Unit(int new_x, int new_y): Point(new_x, new_y)
{
	DEBUG("Unit constructed (default).");
}

Unit::Unit(Unit const &copy)
{
	DEBUG("Unit constructed (copy).");

    this->x = copy.x;
    this->y = copy.y;
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

bool            Unit::include(Point const &p) const
{
    return !(
        p.x < this->x || p.x >= this->x + this->w ||
        p.y < this->y || p.y >= this->y + this->h
     );
}

bool            Unit::touch(Unit const &u) const
{
    return (
        u.x + u.w >= this->x && u.x <= this->x + this->w &&
        u.y + u.h >= this->y && u.y <= this->y + this->h
    );
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
