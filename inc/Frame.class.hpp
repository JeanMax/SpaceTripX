// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Frame.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/01/14 13:38:10 by mc                #+#    #+#             //
//   Updated: 2020/01/14 15:23:44 by mc               ###   ########.fr       //
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
        Frame(Frame const &copy);
        ~Frame(void);
        Frame &operator=(Frame const &copy);

        bool next(void);

        unsigned int get_count(void) const;


    protected:
        unsigned int _count = 0;
        high_resolution_clock::time_point _prev_tick;
        high_resolution_clock::time_point _first_tick;
};


#endif //FRAME_CLASS_HPP
