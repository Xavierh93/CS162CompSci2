//  This is the file for the triangularNumber function which prints and calculates the
//  the triangular number of an integer N provided by user.
//  Created by Xavier Elon Hollingsworth on 2/7/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "triangularNumber.hpp"
#include <iostream>
using namespace std;

//  This function calculates the triangular number of an integer N. It receives int n as a parameter. If n equals 1 it returns n, otherwise it calls this function recursively with a parameter of n-1 and adds n to that. This occurs until n reaches 1.
int triangularNumber(int n)
{
  if(n == 1)
  {
      return n;
  }
  else
  {
      return triangularNumber(n-1) + n;
  }
}
