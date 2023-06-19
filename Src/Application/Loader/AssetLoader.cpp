#include"AssetLoader.h"

void AssetLoader::Init()
{
	LoadAsset("Asset/Model/Bord/Bord.gltf");
	LoadAsset("Asset/Model/Piece/White/King/King.gltf");
	LoadAsset("Asset/Model/Piece/Black/King/King.gltf");
	LoadAsset("Asset/Model/Piece/White/Queen/Queen.gltf");
	LoadAsset("Asset/Model/Piece/Black/Queen/Queen.gltf");
	LoadAsset("Asset/Model/Bord_Selecting/Now/Bord_NowSelecting.gltf");
	LoadAsset("Asset/Model/Bord_Selecting/After/Bord_AfterSelecting.gltf");
	LoadAsset("Asset/Model/Bord_Selecting/Before/Bord_BeforeSelecting.gltf");
	LoadAsset("Asset/Model/Piece/White/Pawn/Pawn.gltf");
	LoadAsset("Asset/Model/Piece/Black/Pawn/Pawn.gltf");
	LoadAsset("Asset/Model/Piece/White/Rook/Rook.gltf");
	LoadAsset("Asset/Model/Piece/Black/Rook/Rook.gltf");
	LoadAsset("Asset/Model/Piece/White/Knight/Knight.gltf");
	LoadAsset("Asset/Model/Piece/Black/Knight/Knight.gltf");
	LoadAsset("Asset/Model/Piece/White/Bishop/Bishop.gltf");
	LoadAsset("Asset/Model/Piece/Black/Bishop/Bishop.gltf");
	LoadAsset("Asset/Model/Bord_Selecting/CanSelect/Bord_CanSelecting.gltf");

}

void AssetLoader::LoadAsset(std::string _pass)
{
	KdAssets::Instance().m_modeldatas.GetData(_pass);
}
