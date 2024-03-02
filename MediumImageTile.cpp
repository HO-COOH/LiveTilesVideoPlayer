#include "pch.h"
#include "MediumImageTile.h"
using namespace TilesBuilder;

MediumImageTile::MediumImageTile(std::wstring fileName) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Image().Src(std::move(fileName)).Placement(Placement::Background)
			),
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Text()(L"Use"),
				Text()(L"Med")
			),
			Binding().Template(TileTemplateNameV3::TileWide)
			(
				Text().HintStyle(TextStyle::Title)(L"Use Medium tile size")
			),
			Binding().Template(TileTemplateNameV3::TileLarge)
			(
				Text().HintStyle(TextStyle::Title)(L"Use Medium tile size")
			)
		)
	)
}
{
}
