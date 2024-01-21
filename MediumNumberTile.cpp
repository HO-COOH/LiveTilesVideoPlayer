#include "pch.h"
#include "MediumNumberTile.h"

using namespace TilesBuilder;

MediumNumberTile::MediumNumberTile(int i) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Text().HintStyle(TextStyle::Title)(std::to_wstring(i))
			),
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Text().HintStyle(TextStyle::Title)(std::to_wstring(i))
			)
		)
	)
}
{
}
