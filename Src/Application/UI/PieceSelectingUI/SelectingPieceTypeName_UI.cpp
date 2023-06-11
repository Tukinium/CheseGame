#include"SelectingPieceTypeName_UI.h"

void SelectingPieceTypeNameUI::Init()
{
	fillPass = "Asset/Textures/UI/PieceSelecting_UI.png";
	UIBaseObject_Class::Init();
	m_rc = { 100,64 };
}

void SelectingPieceTypeNameUI::SetPieceType(int _piecetype)
{
	m_pieceType = _piecetype;
}
