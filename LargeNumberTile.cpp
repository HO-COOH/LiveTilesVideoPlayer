#include "pch.h"
#include "LargeNumberTile.h"

using namespace TilesBuilder;

LargeNumberTile::LargeNumberTile(std::wstring_view i) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Text()(i.data()),
				Text()(L"→Large")
			),
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Text().HintStyle(TextStyle::Title)(i.data()),
				Text()(L"Use Large tile size")
			),
			Binding().Template(TileTemplateNameV3::TileWide)
			(
				Text().HintStyle(TextStyle::Title)(i.data()),
				Text()(L"Use Large tile size")
			),
			Binding().Template(TileTemplateNameV3::TileLarge)
			(
				Text().HintStyle(TextStyle::Title)(i.data())
			)
		)
	)
}
{
}


LargeNumberTile::LargeNumberTile(int i) : LargeNumberTile{std::to_wstring(i)}
{
}

