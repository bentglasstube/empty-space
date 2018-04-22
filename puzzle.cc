#include "puzzle.h"

#include <algorithm>
#include <random>

#include "util.h"

Puzzle::Puzzle() : tiles_("puzzle.png", 4, 16, 16) {
  shuffle();
}

void Puzzle::shuffle() {
  for (size_t i = 0; i < 16; ++i) {
    pieces_[i] = i;
  }

  std::mt19937 rand;
  std::uniform_int_distribution<int> dist(0, 3);

  rand.seed(Util::random_seed());

  for (size_t i = 0; i < 4096; ++i) {
    move(static_cast<Puzzle::Direction>(dist(rand)));
  }
}

bool Puzzle::move(Puzzle::Direction dir) {
  int empty = 0;

  for (size_t i = 0; i < 16; ++ i) {
    if (pieces_[i] == 15) {
      empty = i;
      break;
    }
  }

  switch (dir) {
    case Direction::Left:
      if (empty % 4 == 0) return false;
      std::swap(pieces_[empty - 1], pieces_[empty]);
      break;

    case Direction::Right:
      if (empty % 4 == 3) return false;
      std::swap(pieces_[empty + 1], pieces_[empty]);
      break;

    case Direction::Up:
      if (empty < 4) return false;
      std::swap(pieces_[empty - 4], pieces_[empty]);
      break;

    case Direction::Down:
      if (empty > 11) return false;
      std::swap(pieces_[empty + 4], pieces_[empty]);
      break;
  }

  return true;
}

bool Puzzle::solved() const {
  for (size_t i = 0; i < 16; ++i) {
    if (i != pieces_[i]) return false;
  }

  return true;
}

void Puzzle::draw(Graphics& graphics, int x, int y) const {
  const bool s = solved();

  for (int i = 0; i < 16; ++i) {
    const int xx = (i % 4) * 16 + x;
    const int yy = (i / 4) * 16 + y;

    const int n = (pieces_[i] == 15 && !s) ? 0 : pieces_[i] + 20;
    tiles_.draw(graphics, n, xx, yy);
  }

}
