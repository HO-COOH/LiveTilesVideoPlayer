#include "pch.h"
#include "MediumNumberTile.h"

using namespace TilesBuilder;

MediumNumberTile::MediumNumberTile(int i) : MediumNumberTile{ std::to_wstring(i) }
{
}

MediumNumberTile::MediumNumberTile(std::wstring_view i) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Text().HintStyle(TextStyle::Title)(i.data())
			),
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Text()(i.data()),
				Text()(L"→Med")
			),
			Binding().Template(TileTemplateNameV3::TileWide)
			(
				Text().HintStyle(TextStyle::Title)(i.data()),
				Text()(L"Use Medium tile size")
			),
			Binding().Template(TileTemplateNameV3::TileLarge)
			(
				Text().HintStyle(TextStyle::Title)(i.data()),
				Text()(L"Use Medium tile size")
			)
		)
	)
}
{
}