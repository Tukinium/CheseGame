#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class PieceBaseObject_Class : public BaseObject_Class
{
public:

	virtual void SetDefaultPos(int n) {}
	virtual void Init()override;
	void PieceMoveFixForTeamAreaNotMove();
	enum PieceType
	{
		None,
		WhitePawn0,
		WhitePawn1,
		WhitePawn2,
		WhitePawn3,
		WhitePawn4,
		WhitePawn5,
		WhitePawn6,
		WhitePawn7,
		WhiteKnight0,
		WhiteKnight1,
		WhiteRook0,
		WhiteRook1,
		WhiteBishop0,
		WhiteBishop1,
		WhiteQueen,
		WhiteKing,
		BlackPawn0,
		BlackPawn1,
		BlackPawn2,
		BlackPawn3,
		BlackPawn4,
		BlackPawn5,
		BlackPawn6,
		BlackPawn7,
		BlackKnight0,
		BlackKnight1,
		BlackRook0,
		BlackRook1,
		BlackBishop0,
		BlackBishop1,
		BlackQueen,
		BlackKing,
	};

	void GenMassCenter();

	Math::Vector3 GenRandomMove();

	enum Bord
	{
		Empty,
		Me,
		CanMove,
		Select,
	};
	bool GetCanPropotion()const
	{
		return m_canPropotion;
	}
	bool GetPropotined()const
	{
		return m_propotioned;
	}
	void SetBordInfo(const int h, int w, int _num)
	{
		m_nowBordInfo[h][w] = _num;
	}

	//プロポーション先(0 = Rook,1 = Bishop,2 = Knight,3 = Queen)
	void SetPropotion(const int type)
	{
		m_PropotionType = type;
		m_propotioned = true;
		m_canPropotion = false;
	}
	virtual int SetCanMoveBordInfo(const int h, int w) { return m_canMoveBordInfo[h][w]; };
	virtual void GenCanMoveBordInfo() {};
	bool GetfirstMoved()const
	{
		return m_firstMoved;
	}
	void SetfirstMoved(const bool _moved)
	{
		m_firstMoved = _moved;
	}
	int GetId() const 
	{
		return m_id;
	}
	void SetId(const int _id)
	{
		m_id = _id;
	}
	int GetPoint()const
	{
		return m_point;
	}
protected:
	int m_canMoveBordInfo[8][8] =
	{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};
	int m_nowBordInfo[8][8] =
	{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};

	//ポーン用、最初の2マス動いたかどうか
	bool m_firstMoved = false;

	bool m_propotioned = false;

	//プロポーション先(0 = Rook,1 = Bishop,2 = Knight,3 = Queen)
	int m_PropotionType = -1;
	//IDだヨ
	int m_id = -1;

	int centerH = 0;
	int centerW = 0;
	bool m_canPropotion = false;

	int m_point = -1;
};
