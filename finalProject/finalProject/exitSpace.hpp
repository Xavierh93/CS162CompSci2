//  This is the header file for the derived ExitSpace class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#ifndef exitSpace_hpp
#define exitSpace_hpp

#include "space.hpp"
#include <stdio.h>

class ExitSpace : public Space
{
private:
    
public:
    ExitSpace();
    bool getItem();
    bool getExit();
    bool getTrap();
    
};


#endif /* exitSpace_hpp */
