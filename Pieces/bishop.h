#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include <utility> // For std::pair

//forward declarations
class Tile; 
class Piece;

class Bishop : public Piece {
public:
    Bishop(Tile* position, bool hasMoved, const std::string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const std::string& start, const std::string& end) const override;

private:
    std::pair<int, int> positionToCoordinates(const std::string& position) const;
};

#endif // BISHOP_H
