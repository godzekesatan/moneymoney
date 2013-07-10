#include "map.h"

Map::Map(const std::vector<Sprite> &sprites)
: sprites(sprites) {}

Map::~Map() {}

const Sprite &Map::get(std::vector<Sprite>::size_type n) {
  return sprites.at(n);
}

std::vector<Sprite>::size_type Map::size() {
  return sprites.size();
}
