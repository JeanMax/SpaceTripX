// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Frame.class.cpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
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


/*
** destructor
*/
Frame::~Frame(void)
{
	DEBUG("Frame destructed.");
}


/*
** public
*/
void            Frame::next(void)
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

    // DEBUG("frame duration: " << frame_duration);
}


/*
** getter/setter
*/
unsigned int    Frame::get_count(void) const { return this->_count; }
