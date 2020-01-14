// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/01/13 13:41:54 by mc                #+#    #+#             //
//   Updated: 2020/01/14 11:28:07 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "proj3000.hpp"
#include "Input.class.hpp"
#include <unistd.h>            // DEBUG

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

    // DEBUG
    while (input.get_last_key() != EXIT_KEY) {
        input.read_key();
        MSG("key: " << input.get_last_key());
        usleep(500 * 1000);
    }
    // DEBUG


    if (!finit()) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
