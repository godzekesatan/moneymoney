//
//  Character.cpp
//  moneymoney
//
//  Created by Zeke Virant on 9/11/13.
//
//

#include "Character.h"

Character::Character(){}

Character::Character(string filePath, ofPoint _pos){
  img.loadImage(filePath);
  pos = _pos;
  fileName = filePath;
  
}


void Character::update(double time){
  WayPoint *start = nullptr;
  WayPoint *end = nullptr;
  for (int i = 1; i < waypoints.size(); i++){
    if (waypoints[i].time > time){
      start = &waypoints[i - 1];
      end = &waypoints[i];
      break;
    }
  }
  
  if (start && end) {
    double t = (time - start->time) / (end->time - start->time);
//    cout << "start (" << start->x << ", " << start->y << ")" << endl;
//    cout << "end (" << end->x << ", " << end->y << ")" << endl;
//    cout << "t (" << t << ")" << endl;
    pos.x = ofLerp(start->x, end->x, t);
    pos.y = ofLerp(start->y, end->y, t);
  }
}


void Character::draw(){
  img.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
  img.draw(pos);
}