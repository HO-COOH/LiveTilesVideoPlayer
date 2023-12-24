#include "pch.h"
#include "MediumImageTile.h"
#include "TileBuilder.h"
using namespace TilesBuilder;

MediumImageTile::MediumImageTile(std::wstring fileName) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileMedium)
			(
				Image().Src(std::move(fileName)).Placement(Placement::Background)
			)
		)
	)
}
{
}
