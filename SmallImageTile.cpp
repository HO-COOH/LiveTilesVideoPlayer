#include "pch.h"
#include "SmallImageTile.h"
#include "TileBuilder.h"
using namespace TilesBuilder;

SmallImageTile::SmallImageTile(std::wstring fileName) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Image().Src(std::move(fileName)).Placement(Placement::Background)
			)
		)
	)
	}
{
}
