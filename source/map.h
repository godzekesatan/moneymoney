#ifndef __moneymoney__map__
#define __moneymoney__map__

#include <string>
#include <vector>

struct Sprite {
  double x, y;
  std::string filename;
};

class Map {
public:
  Map() = default;

  Map(const std::vector<Sprite> &sprites);

  virtual ~Map();

  const Sprite &get(std::vector<Sprite>::size_type n);

  std::vector<Sprite>::iterator begin();

  std::vector<Sprite>::iterator end();

  std::vector<Sprite>::size_type size();

private:
  std::vector<Sprite> sprites;
};

#endif /* defined(__moneymoney__map__) */
