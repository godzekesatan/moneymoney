//
//  Character.h
//  moneymoney
//
//  Created by Zeke Virant on 9/11/13.
//
//

#ifndef __moneymoney__Character__
#define __moneymoney__Character__



#include <iostream>
#include "ofMain.h"

struct WayPoint{
  
  double x, y;
  
  double time;
  
};



class Character{
  
public:
  
  Character();
  Character(string filePath, ofPoint _pos);
  
  void draw();
  void update(double time);
  
  ofImage img;
  ofPoint pos;
  string fileName;
  vector<WayPoint> waypoints;
  
  
};


#endif /* defined(__moneymoney__Character__) */
