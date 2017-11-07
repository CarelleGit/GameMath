#include "Entities.h"
#include <iostream>
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
	auto hit = Collides(player.transform, player.collider,
		death.transform, death.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.transform.position, player.rgdb.velocity, hit, .25f);
		player.health -= 1;
		return true;
	}
	return false;
}

inline void Player::speedClamp()
{
	clamp(vec2{ 0,0 }, rgdb.force, vec2{ 5,5 });
}

enum MOVE_BEHAVIOUR { Wander, FollowPlayer, OffScreenLeft, OffScreenRight };

void Karma::move(Player & player, Transform t)
{
	bool left = true;
	float speedToUse = rand() % 800;
	MOVE_BEHAVIOUR mb = Wander;

	if (dist(player.transform.position, transform.position) < 500)
		mb = FollowPlayer;

	else
	{
		// If off screen to the left, move right
		if (transform.position.x < 0)
		{
			mb = OffScreenLeft;
			
		}
		// If off screen to the right, move left
		else if (transform.position.x > 800)
		{
			mb = OffScreenRight;
			
		}
	}

	switch (mb)
	{
	case OffScreenLeft:
		rgdb.force += vec2{ 200,0 };
		break;

	case OffScreenRight:
		rgdb.force -= vec2{ 200,0 };
		break;

	case FollowPlayer:
		if (player.transform.position.x  > transform.position.x)
			rgdb.force += vec2{ 200,0 };

		else if (player.transform.position.x < transform.position.x)
			rgdb.force -= vec2{ 200,0 };
		break;

	case Wander:
		if (left == true) 
			speedToUse = -speedToUse;

		rgdb.force += vec2{ speedToUse , 0 };

		break;

	default:
		break;
	}                                                                           
}

inline void Karma::speedClamp()
{
	clamp(vec2{ 0,0 }, rgdb.force, vec2{ 5,5 });
}

void Player::collisionResolution()
{
	switch (weaponType)
	{
	default:
	case 0:
		//dagger
		level = 0;
		damage = 1;
		break;
	case 1:
		//Sword
		level = 2;
		damage = 3;

	case 2:
		//chainsaw
		level = 4;
		damage = 5;
		break;
	case 3:
		//axe
		level = 6;
		damage = 7;
		break;
	}

}

void Death::move(Player & player, Transform t)
{
}
