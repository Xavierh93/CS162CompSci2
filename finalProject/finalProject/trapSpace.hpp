//  THis is the header file for the derived TrapSpace class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#ifndef trapSpace_hpp
#define trapSpace_hpp

#include "space.hpp"
#include <stdio.h>


class TrapSpace : public Space
{
private:
    
public:
    TrapSpace();
    bool getItem();
    bool getExit();
    bool getTrap();
};


#endif /* trapSpace_hpp */
