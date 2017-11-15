#include "Entities.h"
#include <iostream>
bool collision(Player &player, Karma &karma, Death &death, NPC &npc, Shop &shop,ground &Ground)
{
	auto hit = Collides(player.transform,player.collider,
		karma.transform, karma.collider);
	if (karma.health >= 0)
	{
		if (hit.penetrationDepth > 0)
		{
			player.health -= 1;
			return true;
		}
	}

	auto dHit = Collides(player.transform, player.collider,
		death.transform, death.collider);
	if (dHit.penetrationDepth > 0)
	{
		player.health -= 1;
		return true;
	}


	if ( sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
	{
		auto lnHit = Collides(player.transform, player.right,
			npc.transform, npc.collider);

		if (lnHit.penetrationDepth > 0)
		{
			//std::cout << npc.health << "\n";
			npc.health -= 1;
			//std::cout << npc.health << "\n";
			dynamic_resolution(player.transform.position, player.rgdb.velocity, player.rgdb.mass, npc.transform.position, npc.rgdb.velocity, npc.rgdb.mass, lnHit, .25f);
			return true;
		}

		auto rattack = Collides(player.transform, player.right, karma.transform, karma.collider);
		if (rattack.penetrationDepth > 0)
		{
			//std::cout << karma.health << "\n";
			karma.health -= player.collisionResolution();
			dynamic_resolution(player.transform.position, player.rgdb.velocity, player.rgdb.mass, karma.transform.position, karma.rgdb.velocity, karma.rgdb.mass, rattack, .25f);
			return true;
		}
	}

		if ( sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			auto nHit = Collides(player.transform, player.left,
				npc.transform, npc.collider);

			if (nHit.penetrationDepth > 0)
			{
			//	std::cout << npc.health << "\n";
				npc.health -= 1;
				dynamic_resolution(player.transform.position, player.rgdb.velocity, player.rgdb.mass, npc.transform.position, npc.rgdb.velocity, npc.rgdb.mass, nHit, .25f);

				return true;
			}


			auto lattack = Collides(player.transform, player.left, karma.transform, karma.collider);
			if (lattack.penetrationDepth > 0)
			{
			//	std::cout << karma.health << "\n";
				karma.health -= player.collisionResolution();
				dynamic_resolution(player.transform.position, player.rgdb.velocity, player.rgdb.mass, karma.transform.position, karma.rgdb.velocity, karma.rgdb.mass, lattack, .25f);
				return true;
			}
		}
		auto hit3 = Collides(player.transform, player.collider,
			shop.transform, shop.collider);

		if (hit3.penetrationDepth > 0)
		{
	
			//dynamic_resolution(player.transform.position, player.rgdb.velocity, player.rgdb.mass, shop.transform.position, karma.rgdb.velocity, karma.rgdb.mass, hit3, .25f);
			return true;
		}

		auto grounded = Collides(player.transform, player.collider, Ground.transform, Ground.collider);
		if (grounded.penetrationDepth >= 0)
		{
			Ground.isGrounded = true;
			player.control.grounded = Ground.isGrounded;

			//std::cout << "Test" << std::endl;

			if (grounded.penetrationDepth > 0)
			{
				static_resolution(player.transform.position, player.rgdb.velocity, grounded, 0);
				std::cout << player.transform.position.y << " " << player.transform.position.x <<"\n";
				return true;
			}
		}
		else
		{
			Ground.isGrounded = player.control.grounded = false;
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



void Player::update(ground &Ground)
{
	if (!sfw::getKey('D') && sfw::getMouseButton(MOUSE_BUTTON_LEFT))
	{
		left.box.position = vec2{ -.5f,0 };
		left.box.extents = vec2{ .5f,.5f };
	}
	if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
	{
		right.box.position = vec2{ .5f,0 };
		right.box.extents = vec2{ .5f,.5f };
	}
	if (Ground.isGrounded == true)
	{
		if (sfw::getKey(' '))
		{
			rgdb.impulse.y = 200;
			Ground.isGrounded = false;
		}
	}
}

enum MOVE_BEHAVIOUR { Wander, FollowPlayer, OffScreenLeft, OffScreenRight };

void Karma::move(Player & player, Transform t)
{
	bool left = true;
	float speedToUse = 100;// rand() % 800;
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
		rgdb.force = vec2{ speedToUse,0 };
		break;

	case OffScreenRight:
		rgdb.force = vec2{ speedToUse,0 };
		break;

	case FollowPlayer:
		if (player.transform.position.x  > transform.position.x)
			rgdb.force += vec2{ speedToUse,0 };

		else if (player.transform.position.x < transform.position.x)
			rgdb.force -= vec2{ speedToUse,0 };
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
				rgdb.force += vec2{ speedToUse,0 };
			}
			if (!directrion)
			{
				//transform.position.x += 5;
				rgdb.force -= vec2{ speedToUse,0 };
			}
			
		break;

	default:
		break;
	}                                                                           
}


void Karma::respawn()
{
	if (health <= 0)
	{
		time -= sfw::getDeltaTime();
		//std::cout << time << "\n";
		if (time <= 0)
		{
			health = 15;
			time = 10;
			transform.position = vec2{ 600,40 };
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
	float speedToUse = 50; //rand() % 800;
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
		rgdb.force = vec2{ speedToUse,0 };
		break;

	case OffScreenRight:
		rgdb.force = vec2{ speedToUse,0 };
		break;

	case FollowPlayer:
		if (player.transform.position.x  > transform.position.x)
			rgdb.force = vec2{ speedToUse,0 };

		else if (player.transform.position.x < transform.position.x)
			rgdb.force = vec2{ speedToUse,0 };
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
			rgdb.force -= vec2{ speedToUse,0 };
		}
		if (!directrion)
		{
			//transform.position.x += 5;
			rgdb.force += vec2{ speedToUse,0 };
		}

		break;

	default:
		break;
	}
}

void NPC::move(Player & player, Transform t)
{
	float speedToUse = 100;// rand() % 800;
	MOVE_BEHAVIOUR mb = Wander;

	if (dist(player.transform.position, transform.position) < 400)
		mb = FollowPlayer;
	switch (mb)
	{
	case OffScreenLeft:
		rgdb.force = vec2{ speedToUse,0 };
		break;

	case OffScreenRight:
		rgdb.force = vec2{ speedToUse,0 };
		break;

	case FollowPlayer:
		if (player.transform.position.x  > transform.position.x)
			rgdb.force -= vec2{ speedToUse,0 };

		else if (player.transform.position.x < transform.position.x)
			rgdb.force += vec2{ speedToUse,0 };
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
			rgdb.force = vec2{ speedToUse,0 };
		}
		if (!directrion)
		{
			//transform.position.x += 5;
			rgdb.force = vec2{ speedToUse,0 };
		}

		break;

	default:
		break;
	}
}
