#ifndef __moneymoney__map__
#define __moneymoney__map__

#include <string>
#include <vector>

/**
 * Represents a sprite, loaded from the given filename, at (x, y).
 */
struct Sprite {
  /**
   * The coordinates of the sprite.
   */
  double x, y;

  /**
   * The file holding the sprite data.
   */
  std::string filename;
};

/**
 * Represents the game map which contains many sprites at various locations.
 */
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
  /**
   * The list of sprites visible on the game map.
   */
  std::vector<Sprite> sprites;
};

#endif /* defined(__moneymoney__map__) */
