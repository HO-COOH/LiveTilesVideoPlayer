#include "pch.h"
#include "LargeImageTile.h"

using namespace TilesBuilder;

LargeImageTile::LargeImageTile(std::wstring fileName) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileLarge)
			(
				Image().Src(std::move(fileName)).Placement(Placement::Background)
			),
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Text()(L"Use"),
				Text()(L"Large")
			),
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Text().HintStyle(TextStyle::Title)(L"Use"),
				Text().HintStyle(TextStyle::Title)(L"Large"),
				Text()(L"tile size")
			),
			Binding().Template(TileTemplateNameV3::TileWide)
			(
				Text().HintStyle(TextStyle::Title)(L"Use Large tile size")
			)
		)
	)
}
{
}
