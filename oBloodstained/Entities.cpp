#include "Entities.h"

bool collision(Player & player, Karma & karma)
{
	auto hit = Collides(player.transform,player.collider,
		karma.transform, karma.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.transform.position, player.rgdb.velocity, hit, .25f);
		player.health -= 1;
		return true;
	}
	return false;
}

bool collision(Player & player, Death & death)
{
	return false;
}

inline void Player::speedClamp()
{
	clamp(vec2{ 0,0 }, rgdb.force, vec2{ 5,5 });
}

void Karma::move(Player & player, Transform t)
{
	if (dist(player.transform.position, transform.position) < 100 && player.transform.position.x  > transform.position.x)
	{
		rgdb.force += vec2{ 1000,0 };
	}
	if (dist(player.transform.position, transform.position) < 100 && player.transform.position.x < transform.position.x)
	{
		rgdb.force -= vec2{ 1000,0 };
	}
	if (transform.position.x <= 0)
	{
		transform.position += vec2{ 1000,0 };
	}
	if (transform.position.x >= 600)
	{
		transform.position -= vec2{ 1000,0 };
	}
}

inline void Karma::speedClamp()
{
	clamp(vec2{ 0,0 }, rgdb.force, vec2{ 5,5 });
}

void Death::move(Player & player, Transform t)
{
}
