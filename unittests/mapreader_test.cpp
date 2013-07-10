#include <gtest/gtest.h>
#include <iostream>
#include <picojson.h>
#include <sstream>

#include "mapreader.h"

TEST(MapReaderTest, ReadMap) {
  MapReader reader;
  Map map = reader.ReadMap("data/map.json");
  EXPECT_EQ(2, map.size());
  Sprite s0 = map.get(0);
  EXPECT_EQ(1, s0.x);
  EXPECT_EQ(2, s0.y);
  EXPECT_EQ("tile000.png", s0.filename);
  Sprite s1 = map.get(1);
  EXPECT_EQ(100, s1.x);
  EXPECT_EQ(200, s1.y);
  EXPECT_EQ("tile001.png", s1.filename);
}
