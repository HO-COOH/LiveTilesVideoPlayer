#include "pch.h"
#include "SmallImageTile.h"

using namespace TilesBuilder;

SmallImageTile::SmallImageTile(std::wstring fileName) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Image().Src(std::move(fileName)).Placement(Placement::Background)
			),
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Text().HintStyle(TextStyle::Title)(L"Use"),
				Text().HintStyle(TextStyle::Title)(L"Small"),
				Text()(L"tile size")
			),
			Binding().Template(TileTemplateNameV3::TileWide)
			(
				Text().HintStyle(TextStyle::Title)(L"Use Small tile size")
			),
			Binding().Template(TileTemplateNameV3::TileLarge)
			(
				Text().HintStyle(TextStyle::Title)(L"Use Small tile size")
			)
		)
	)
}
{
}
