//
//  Player.cpp
//  papTermTwoCourseWork
//
//  Created by Charles Ringer on 15/02/2016.
//
//

#include "Player.hpp"
#include "ChickPiece.hpp"
#include "HenPiece.hpp"
#include "GiraffePiece.hpp"
#include "LionPiece.hpp"
#include "ElephantPiece.hpp"

Player::Player(bool isAI): ai(isAI) {}

Player::Player(const Player &other)
{
    ai = other.ai;
    imgBank = other.getImageBank();
    for(GamePiecePtr bankPiece : other.getBankConst())
    {
        //assert(bankPiece);
        if (!bankPiece) continue;
        int pieceX = bankPiece->getX();
        int pieceY = bankPiece->getY();
        PieceType type = bankPiece->getType();
        
        if (type == PieceType::GIRAFFE)
            bank.push_back(make_shared<GiraffePiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::LION)
            bank.push_back(make_shared<LionPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::ELEPHANT)
            bank.push_back(make_shared<ElephantPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::CHICK)
            bank.push_back(make_shared<ChickPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::HEN)
            bank.push_back(make_shared<HenPiece>(pieceX,pieceY, this, imgBank));
    }
}

HumanPlayer::HumanPlayer(const HumanPlayer &player): Player(false)
{
    imgBank = player.getImageBank();
    for(GamePiecePtr bankPiece : player.getBankConst())
    {
        //assert(bankPiece);
        if (!bankPiece) continue;
        int pieceX = bankPiece->getX();
        int pieceY = bankPiece->getY();
        PieceType type = bankPiece->getType();
        
        if (type == PieceType::GIRAFFE)
            bank.push_back(make_shared<GiraffePiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::LION)
            bank.push_back(make_shared<LionPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::ELEPHANT)
            bank.push_back(make_shared<ElephantPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::CHICK)
            bank.push_back(make_shared<ChickPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::HEN)
            bank.push_back(make_shared<HenPiece>(pieceX,pieceY, this, imgBank));
    }
}

Player::~Player(){}


void Player::addToBank(PieceType type){};

HumanPlayer::HumanPlayer(shared_ptr<ImageBank> _imgBank): Player(false)
{
    imgBank = _imgBank;
}


HumanPlayer::~HumanPlayer(){}

void HumanPlayer::addToBank(PieceType type)
{
    int row = 0;
    if (bank.size() >= 5) row = 1;
    GamePiecePtr piece;
    if (type == PieceType::GIRAFFE)
        piece = make_shared<GiraffePiece>((bank.size()-1)-(row*5),4+row, this, imgBank);
    else if (type == PieceType::LION)
        piece = make_shared<LionPiece>((bank.size()-1)-(row*5),4+row,this, imgBank);
    else if (type == PieceType::ELEPHANT)
        piece = make_shared<ElephantPiece>((bank.size()-1)-(row*5),4+row,this, imgBank);
    else if (type == PieceType::CHICK)
        piece = make_shared<ChickPiece>((bank.size()-1)-(row*5),4+row, this, imgBank);
    else if (type == PieceType::HEN)
        piece = make_shared<ChickPiece>((bank.size()-1)-(row*5),4+row, this, imgBank);
    assert(piece);
    bank.push_back(piece);
}

shared_ptr<Player> HumanPlayer::clonePlayer()
{
    shared_ptr<Player> clone = make_shared<HumanPlayer>(*this);
    return clone;
}


AIPlayer::AIPlayer(shared_ptr<ImageBank> _imgBank): Player(true)
{
    
    imgBank = _imgBank;
}

AIPlayer::AIPlayer( const AIPlayer &player): Player(true)
{
    imgBank = player.getImageBank();
    for(GamePiecePtr bankPiece : player.getBankConst())
    {
        //assert(bankPiece);
        if(!bankPiece) continue;
        int pieceX = bankPiece->getX();
        int pieceY = bankPiece->getY();
        PieceType type = bankPiece->getType();
        
        if (type == PieceType::GIRAFFE)
            bank.push_back(make_shared<GiraffePiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::LION)
            bank.push_back(make_shared<LionPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::ELEPHANT)
            bank.push_back(make_shared<ElephantPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::CHICK)
            bank.push_back(make_shared<ChickPiece>(pieceX,pieceY, this, imgBank));
        else if (type == PieceType::HEN)
            bank.push_back(make_shared<HenPiece>(pieceX,pieceY, this, imgBank));
    }
}

AIPlayer::~AIPlayer(){}

void AIPlayer::addToBank(PieceType type)
{
    int row = 0;
    if (bank.size() > 5) row = 1;
    GamePiecePtr piece;
    if (type == PieceType::GIRAFFE)
        piece = make_shared<GiraffePiece>(bank.size()-1-(row*5),-(1+row), this, imgBank);
    else if (type == PieceType::LION)
        piece = make_shared<LionPiece>(bank.size()-1-(row*5),-(1+row),this, imgBank);
    else if (type == PieceType::ELEPHANT)
        piece = make_shared<ElephantPiece>(bank.size()-1-(row*5),-(1+row), this, imgBank);
    else if (type == PieceType::CHICK)
        piece = make_shared<ChickPiece>(bank.size()-1-(row*5),-(1+row), this, imgBank);
    else if (type == PieceType::HEN)
        piece = make_shared<ChickPiece>(bank.size()-1-(row*5),-(1+row), this, imgBank);
    assert(piece);
    bank.push_back(piece);
}

shared_ptr<Player> AIPlayer::clonePlayer()
{
    shared_ptr<Player> clone = make_shared<AIPlayer>(*this);
    return clone;
}
