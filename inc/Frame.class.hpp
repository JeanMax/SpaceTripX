// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Frame.class.hpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef FRAME_CLASS_HPP
# define FRAME_CLASS_HPP

# define FRAME_PER_SECOND 2
# define FRAME_DURATION_MS (1000 / FRAME_PER_SECOND)

# include <thread>  // sleep_for
# include <chrono>
# include "log.hpp"

using namespace std::chrono;


class Frame
{
    public:
        Frame(void);
        ~Frame(void);

        void next(void);

        unsigned int get_count(void) const;


    protected:
        unsigned int _count = 0;
        high_resolution_clock::time_point _prev_tick;
        high_resolution_clock::time_point _first_tick;
};


#endif //FRAME_CLASS_HPP
