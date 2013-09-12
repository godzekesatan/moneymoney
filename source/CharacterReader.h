//
//  CharacterReader.h
//  moneymoney
//
//  Created by Zeke Virant on 9/12/13.
//
//

#ifndef __moneymoney__CharacterReader__
#define __moneymoney__CharacterReader__

#include <iostream>
#include <picojson.h>
#include <string>

#include "Character.h"

/**
 * Reads characters from a JSON file.
 */
class CharacterReader {
public:
  CharacterReader();
  
  virtual ~CharacterReader();
  
  vector<Character> ReadCharacters(const std::string &filename);
  
  Character ReadCharacter(const picojson::value &character);
  
  WayPoint ReadWayPoint(const picojson::value &waypoint);
  
};

#endif /* defined(__moneymoney__CharacterReader__) */
