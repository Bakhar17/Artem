#include "pch.h"
#include "E:\\labs\\Artem\\Tests\\Tests\\Header.h"
#include <fstream>
#include <string>
TEST(TestPos, TestName) {
	string line = "Pikachu Pikachu Pokemon Pikachu";
	Er("Pikachu", line);
	auto pos = line.find("Pikachu");
  EXPECT_EQ(pos,string::npos);
}