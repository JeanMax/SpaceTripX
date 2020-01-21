// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Random.class.hpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef RANDOM_CLASS_HPP
# define RANDOM_CLASS_HPP

# include "log.hpp"

# include <iostream>
# include <random>


class Random {
    public:
        Random(const int min, const int max);
        ~Random(void);

        int generate(void);

    protected:
        std::mt19937 mt;  //seed
        std::uniform_int_distribution<int> dist;
};


#endif //RANDOM_CLASS_HPP
