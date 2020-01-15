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
    if (p.x < this->x || p.x >= this->x + this->w
        || p.y < this->y || p.y >= this->y + this->h) {
        return false;
    }

    //TODO: I could have optimized that if I wasn't a dumb ass
    Point offset;

    for (offset.y = 0; offset.y < this->h; offset.y++) {
        for (offset.x = 0; offset.x < this->w; offset.x++) {
            if (p == *this + offset && AT(this->sprite, offset) != EMPTY) {
                return true;
            }
        }
    }

    return false;
}

bool            Unit::touch(Unit const &u) const
{
    Point offset, p;

    for (offset.y = 0; offset.y < u.h; offset.y++) {
        for (offset.x = 0; offset.x < u.w; offset.x++) {
            p = u + offset;
            if (AT(u.sprite, p) && this->include(p)) {
                return true;
            }
        }
    }

    return false;
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
