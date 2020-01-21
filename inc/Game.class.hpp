// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Game.class.hpp                                            (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "log.hpp"
# include "Rectangle.class.hpp"
# include "Player.class.hpp"
# include "Output.class.hpp"  // just for windows dimensions

# define MAX_PLAYERS 4


class Game
{
    public:
        Game(const int n_players = 1);
        ~Game(void);

        void play_turn(void);
        bool game_over(void) const;

        Player    players[MAX_PLAYERS];

    protected:
        Rectangle _map = Rectangle(1, 1, GAME_WIDTH - 2, GAME_HEIGHT - 2);
        const int _n_players;
};


#endif //GAME_CLASS_HPP
