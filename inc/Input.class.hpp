// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Input.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/01/14 10:37:49 by mc                #+#    #+#             //
//   Updated: 2020/01/14 15:42:11 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP


# define NOT_A_KEY 0
# define EXIT_KEY 27
# define LEFT_KEY 'q'
# define RIGHT_KEY 'd'
# define UP_KEY 'z'
# define DOWN_KEY 's'
# define SHOOT_KEY ' '

# define READ_KEY_TIMEOUT_MS 50

# include <curses.h>

# include "log.hpp"


class Input
{
    public:
        Input(void);
        Input(Input const &copy);
        ~Input(void);
        Input &operator=(Input const &copy);

        char read_key(void);

        char get_last_key(void) const;


    protected:
        char _last_key = NOT_A_KEY;
};


#endif //INPUT_CLASS_HPP
