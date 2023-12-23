#include "pch.h"
#include "SmallNumberTile.h"
#include "TileBuilder.h"
using namespace TilesBuilder;
SmallNumberTile::SmallNumberTile(int i) : TileNotification{
	Tile()
	(
		Visual()
		(
			Binding().Template(TileTemplateNameV3::TileSmall)
			(
				Text().HintStyle(TextStyle::Title)(std::to_wstring(i))
			)
		)
	)
}
{
}
