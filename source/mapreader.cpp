#include <fstream>
#include <picojson.h>
#include <string>
#include <vector>

#include "checks.h"
#include "map.h"
#include "mapreader.h"

MapReader::MapReader() {}

MapReader::~MapReader() {}

Map MapReader::ReadMap(const std::string &filename) {
  std::ifstream in(filename.c_str());
  CHECK_STATE(!in.fail());
  picojson::value value;
  in >> value;
  std::string error = picojson::get_last_error();
  if (!error.empty()) {
    FAIL(error);
  }
  CHECK_STATE(value.is<picojson::array>());
  std::vector<Sprite> sprites;
  for (auto sprite : value.get<picojson::array>()) {
    sprites.push_back(ReadSprite(sprite));
  }
  return Map(sprites);
}

Sprite MapReader::ReadSprite(const picojson::value &sprite) {
  CHECK_STATE(sprite.is<picojson::object>());
  picojson::object object = sprite.get<picojson::object>();
  CHECK_STATE(object["x"].is<double>());
  CHECK_STATE(object["y"].is<double>());
  CHECK_STATE(object["filename"].is<std::string>());
  Sprite result;
  result.x = object["x"].get<double>();
  result.y = object["y"].get<double>();
  result.filename = object["filename"].get<std::string>();
  return result;
}
