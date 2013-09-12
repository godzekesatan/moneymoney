//
//  CharacterWriter.cpp
//  moneymoney
//
//  Created by Zeke Virant on 9/12/13.
//
//

#include "CharacterWriter.h"
#include <fstream>
#include <picojson.h>
#include <string>
#include <vector>
#include "checks.h"

CharacterWriter::CharacterWriter(){
  
}

CharacterWriter::~CharacterWriter(){
  
}

void CharacterWriter::WriteCharacters(const std::string &filename, vector<Character> &characters){
  std::ofstream out(ofToDataPath(filename).c_str());
  CHECK_STATE(!out.fail());
  picojson::array array = picojson::array();
  for (auto character : characters){
    array.push_back(WriteCharacter(character));
  }
  picojson::value v(array);
  out << v;
  out.close();
  
  
  
}

picojson::value CharacterWriter::WriteCharacter(Character &character){
  picojson::object object = picojson::object();
  object["x"] = picojson::value(character.waypoints[0].x);
  object["y"] = picojson::value(character.waypoints[0].y);
  object["filename"] = picojson::value(character.fileName);
  picojson::array array;
  for (int i = 1; i < character.waypoints.size(); i++){
    array.push_back(WriteWayPoint(character.waypoints[i]));
  }
  object["waypoints"] = picojson::value(array);
  return picojson::value(object);
  
  
}

picojson::value CharacterWriter::WriteWayPoint(WayPoint &waypoint){
  picojson::object object = picojson::object();
  object["x"] = picojson::value(waypoint.x);
  object["y"] = picojson::value(waypoint.y);
  object["time"] = picojson::value(waypoint.time);
  return picojson::value(object);
}
