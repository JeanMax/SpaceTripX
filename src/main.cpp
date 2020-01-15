// ************************************************************************** //
//                                                              _.._..,_,_    //
//   main.cpp                                                  (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
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
