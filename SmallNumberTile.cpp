#include "pch.h"
#include "SmallNumberTile.h"

using namespace TilesBuilder;
SmallNumberTile::SmallNumberTile(int i) : SmallNumberTile{std::to_wstring(i)}
{
}

SmallNumberTile::SmallNumberTile(std::wstring_view i) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Text().HintStyle(TextStyle::Title)(i.data())
			),
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Text().HintStyle(TextStyle::Title)(i.data()),
				Text()(L"Use Small tile size")
			),
			Binding().Template(TileTemplateNameV3::TileWide)
			(
				Text().HintStyle(TextStyle::Title)(i.data()),
				Text()(L"Use Small tile size")
			),
			Binding().Template(TileTemplateNameV3::TileLarge)
			(
				Text().HintStyle(TextStyle::Title)(i.data()),
				Text()(L"Use Small tile size")
			)
		)
	)
}
{
}