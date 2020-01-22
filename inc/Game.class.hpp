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

# include "Random.class.hpp"
# include "Output.class.hpp"  // just for windows dimensions

# include "Rectangle.class.hpp"
# include "Player.class.hpp"
# include "Particle.class.hpp"
# include "Monster.class.hpp"

# define MAX_PLAYERS 4
# define MAX_PARTICLES 20
# define MAX_MONSTERS 32

# define MONSTER_WAVE_INTERVAL 30


class Game
{
    public:
        Game(const int n_players = 1);
        ~Game(void);

        void play_turn(void);
        bool over(void) const;

        Player    players[MAX_PLAYERS];
        Monster   monsters[MAX_MONSTERS];
        Particle  particles[MAX_PARTICLES];

    protected:
        Random    _random = Random(1, GAME_WIDTH - 2);
        Rectangle _map = Rectangle(1, 1, GAME_WIDTH - 2, GAME_HEIGHT - 2);
        int _turns = 0;
        int _n_monsters = 0;
        const int _n_players;
};


#endif //GAME_CLASS_HPP
