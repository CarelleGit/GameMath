#include "Player.h"

bool doCollision(Player & player, const Wall & wall)
{
	auto hit = collides(player.trans, player.collider,
		wall.trans, wall.coll);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.trans.position, player.rgdb.velocity, hit, .25f);
		return true;
	}
	return false;
}
