#include "food.h"

Food Food::operator+(const Food &rhs) const {
	float addedCals = this->calories() + rhs.calories();
	std::string newName = this->name() + " " + rhs.name();
  return Food(newName, addedCals);
}

bool Food::operator<(const Food &rhs) const {
	if (this->calories() < rhs.calories()) {
		return true;
	}
	else
		return false;
}

bool Food::operator==(const Food &rhs) const {
	if ((this->name() == rhs.name()) && (this->calories() == rhs.calories())) {
		return true;
  }
  return false;
}
