//
//  CharacterWriter.h
//  moneymoney
//
//  Created by Zeke Virant on 9/12/13.
//
//

#ifndef __moneymoney__CharacterWriter__
#define __moneymoney__CharacterWriter__

#include <iostream>
#include <picojson.h>
#include <string>
#include "Character.h"

class CharacterWriter{
public:
  
  CharacterWriter();
    
  virtual ~CharacterWriter();
  
  void WriteCharacters(const std::string &filename, vector<Character> &characters);

  picojson::value WriteCharacter(Character &character);

  picojson::value WriteWayPoint(WayPoint &waypoint);


};



#endif /* defined(__moneymoney__CharacterWriter__) */
