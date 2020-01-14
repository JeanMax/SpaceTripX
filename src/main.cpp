// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/01/13 13:41:54 by mc                #+#    #+#             //
//   Updated: 2020/01/14 15:42:47 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "proj3000.hpp"
#include "Input.class.hpp"
#include "Frame.class.hpp"

static bool init()
{
    initscr(); //init ncurses

    return true;
}

static int  finit(bool quit = false)
{
    endwin();

    if (quit) {
        exit(EXIT_SUCCESS);
    }
    return true;
}

int         main(int ac, char **av)
{
    MSG("ac: " << ac);
    while (*av)
        MSG("av: " << *av++);

    if (!init()) {
        return EXIT_FAILURE;
    }

    Input input = Input();
    Frame frame = Frame();

    // DEBUG
    while (input.get_last_key() != EXIT_KEY) {
        frame.next();
        input.read_key();
        clear();
        MSG("key: " << input.get_last_key());
    }
    // DEBUG


    if (!finit()) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
