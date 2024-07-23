#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include <utility> // For std::pair

//forward declarations 
class Piece;

class Bishop : public Piece {
public:
    Bishop(string currPos, bool hasMoved, const std::string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const std::string& start, const std::string& end) const override;

private:
    std::pair<int, int> positionToCoordinates(const string& position) const;
};

#endif // BISHOP_H
