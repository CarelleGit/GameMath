#include "Entities.h"
#include <iostream>
bool collision(Player &player, Karma &karma, Death &death, NPC &npc)
{
	auto hit = Collides(player.transform,player.collider,
		karma.transform, karma.collider);

	if (hit.penetrationDepth > 0)
	{
		player.health -= 1;
		dynamic_resolution(player.transform.position,player.rgdb.velocity, player.rgdb.mass, karma.transform.position,karma.rgdb.velocity,karma.rgdb.mass,hit, 1);
		return true;
	}

	auto dHit = Collides(player.transform, player.collider,
		death.transform, death.collider);

	if (dHit.penetrationDepth > 0)
	{
		dynamic_resolution(player.transform.position, player.rgdb.velocity, player.rgdb.mass, death.transform.position, death.rgdb.velocity, death.rgdb.mass, dHit, 1);
		player.health -= 1;
		return true;
	}

	auto nHit = Collides(player.transform, player.left,
		npc.transform, npc.collider);

	if (nHit.penetrationDepth > 0)
	{
		npc.health -= 1;
		return true;
	}


	auto lnHit = Collides(player.transform, player.right,
		npc.transform, npc.collider);

	if (lnHit.penetrationDepth > 0)
	{
		npc.health -= 1;
		return true;
	}

	auto rattack = Collides(player.transform, player.right, karma.transform, karma.collider);
		if (rattack.penetrationDepth > 0)
		{
			karma.health -= player.collisionResolution();
			return true;
		}

	auto lattack = Collides(player.transform, player.left, karma.transform, karma.collider);
		if (lattack.penetrationDepth > 0)
		{
			karma.health -= player.collisionResolution();
			return true;
		}

	return false;
}

void leveling(Karma &karma, Player &player, NPC &npc)
{
	if (npc.health <= 0)
	{
		player.xp += 1;
	}
		if (karma.health <= 0)
		{
			player.xp += 10;
		}
		if (player.xp == 100)
		{
			player.level = 1;
		}
		if (player.xp == 200)
		{
			player.level = 2;
		}
		if (player.xp == 300)
		{
			player.level = 3;
		}
		if (player.xp == 400)
		{
			player.level = 4;
		}
		if (player.xp == 500)
		{
			player.level = 5;
		}
		if (player.xp == 600)
		{
			player.level = 6;
		}
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
		if (transform.position.x > 799)
		{
			directrion = false;
		}
		if (transform.position.x < 1)
		{
			directrion = true;
		}
			if (directrion)
			{
				rgdb.force += vec2{ 800,0 };
			}
			if (!directrion)
			{
				//transform.position.x += 5;
				rgdb.force -= vec2{ 800,0 };
			}
			
		break;

	default:
		break;
	}                                                                           
}

inline void Karma::speedClamp()
{
	clamp(vec2{ 0,0 }, rgdb.force, vec2{ 5,5 });
}

void Karma::respawn()
{
	
	if (health <=0)
	{
		for (int dt = sfw::getDeltaTime(); dt < 102; dt++)
		{
			if (dt == 100)
			{
				health = 15;
				transform.position.x = 1;
				dt = 0;
			}
			else
			{
				dt++;
			}
		}
	}
	
}

int Player::collisionResolution()
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
	return damage;
}



void Death::move(Player & player, Transform t)
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
		if (transform.position.x > 799)
		{
			directrion = false;
		}
		if (transform.position.x < 1)
		{
			directrion = true;
		}
		if (directrion)
		{
			rgdb.force += vec2{ 800,0 };
		}
		if (!directrion)
		{
			//transform.position.x += 5;
			rgdb.force -= vec2{ 800,0 };
		}

		break;

	default:
		break;
	}
}

void NPC::move(Player & player, Transform t)
{
	float speedToUse = rand() % 800;
	MOVE_BEHAVIOUR mb = Wander;

	if (dist(player.transform.position, transform.position) < 400)
		mb = FollowPlayer;
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
			rgdb.force -= vec2{ 200,0 };

		else if (player.transform.position.x < transform.position.x)
			rgdb.force += vec2{ 200,0 };
		break;

	case Wander:
		if (transform.position.x > 799)
		{
			directrion = false;
		}
		if (transform.position.x < 1)
		{
			directrion = true;
		}
		if (directrion)
		{
			rgdb.force += vec2{ 800,0 };
		}
		if (!directrion)
		{
			//transform.position.x += 5;
			rgdb.force -= vec2{ 800,0 };
		}

		break;

	default:
		break;
	}
}
