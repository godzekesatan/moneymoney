#ifndef __moneymoney__mapreader__
#define __moneymoney__mapreader__

#include <picojson.h>
#include <string>

#include "map.h"

class MapReader {
public:
  MapReader();

  virtual ~MapReader();

  Map ReadMap(const std::string &filename);

  Sprite ReadSprite(const picojson::value &sprite);
};

#endif /* defined(__moneymoney__mapreader__) */
