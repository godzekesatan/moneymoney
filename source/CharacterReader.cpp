//
//  CharacterReader.cpp
//  moneymoney
//
//  Created by Zeke Virant on 9/12/13.
//
//

#include "CharacterReader.h"
#include <fstream>
#include <picojson.h>
#include <string>
#include <vector>
#include "checks.h"

CharacterReader::CharacterReader() {}

CharacterReader::~CharacterReader() {}

std::vector<Character> CharacterReader::ReadCharacters(const std::string &filename) {
  std::ifstream in(filename.c_str());
  CHECK_STATE(!in.fail());
  picojson::value value;
  in >> value;
  std::string error = picojson::get_last_error();
  if (!error.empty()) {
    FAIL(error);
  }
  CHECK_STATE(value.is<picojson::array>());
  picojson::array array = value.get<picojson::array>();
  std::vector<Character> characters;
  for (picojson::value character : array) {
    characters.push_back(ReadCharacter(character));
  }
  return characters;
}

Character CharacterReader::ReadCharacter(const picojson::value &character) {
  CHECK_STATE(character.is<picojson::object>());
  picojson::object object = character.get<picojson::object>();
  CHECK_STATE(object["x"].is<double>());
  CHECK_STATE(object["y"].is<double>());
  CHECK_STATE(object["filename"].is<std::string>());
  Character result = Character(object["filename"].get<std::string>(), ofPoint(object["x"].get<double>(), object["y"].get<double>()));
  WayPoint start;
  start.x = result.pos.x;
  start.y = result.pos.y;
  start.time = 0;
  result.waypoints.push_back(start);
  if (object.find("waypoints") != object.end()){
    picojson::array array = object["waypoints"].get<picojson::array>();
    for (picojson::value waypoint : array){
      result.waypoints.push_back(ReadWayPoint(waypoint));
    }
  }
  return result;
}

WayPoint CharacterReader::ReadWayPoint(const picojson::value &waypoint){
  CHECK_STATE(waypoint.is<picojson::object>());
  picojson::object object = waypoint.get<picojson::object>();
  CHECK_STATE(object["x"].is<double>());
  CHECK_STATE(object["y"].is<double>());
  CHECK_STATE(object["time"].is<double>());
  WayPoint result;
  result.x = object["x"].get<double>();
  result.y = object["y"].get<double>();
  result.time = object["time"].get<double>();
  return result;
   
}




