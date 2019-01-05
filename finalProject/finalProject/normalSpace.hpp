//  This is the header file for the derived NormalSpace class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#ifndef normalSpace_hpp
#define normalSpace_hpp

#include "space.hpp"
#include "functions.hpp"
#include <stdio.h>

class NormalSpace : public Space
{
private:
    
public:
    NormalSpace();
    bool getItem();
    bool getExit();
    bool getTrap();
};

#endif /* normalSpace_hpp */
