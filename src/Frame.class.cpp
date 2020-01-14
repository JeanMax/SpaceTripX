// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Frame.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/01/14 13:39:29 by mc                #+#    #+#             //
//   Updated: 2020/01/14 15:22:10 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Frame.class.hpp"


/*
** constructor
*/
Frame::Frame()
{
	DEBUG("Frame constructed (default).");

    this->_first_tick = high_resolution_clock::now();
    this->_prev_tick = this->_first_tick;
}

Frame::Frame(Frame const &copy)
{
	DEBUG("Frame constructed (copy).");

    this->_first_tick = copy._first_tick;
    this->_prev_tick = copy._prev_tick;
}


/*
** destructor
*/
Frame::~Frame(void)
{
	DEBUG("Frame destructed.");
}


/*
** operator overload
*/
Frame           &Frame::operator=(Frame const &copy)
{
	DEBUG("Frame operator= called.");

    this->_first_tick = copy._first_tick;
    this->_prev_tick = copy._prev_tick;

	return *this;
}


/*
** public
*/
bool            Frame::next(void)
{
    milliseconds::rep frame_duration = duration_cast<milliseconds>(
        high_resolution_clock::now() - this->_prev_tick
    ).count();
    milliseconds::rep to_sleep = FRAME_DURATION_MS - frame_duration;

    if (to_sleep > 0) {
        std::this_thread::sleep_for(milliseconds(to_sleep));
    }

    this->_prev_tick = high_resolution_clock::now();
    this->_count++;

    DEBUG("frame duration: " << frame_duration);


    return true;  // TODO
}


/*
** getter/setter
*/
unsigned int    Frame::get_count(void) const { return this->_count; }
