#include "Entities.h"
#include <iostream>
bool collision(Player &player, Karma &karma, Death &death, NPC &npc, ground &Ground)
{
	auto hit = Collides(player.transform,player.collider,
		karma.transform, karma.collider);
	if (karma.health >= 0)
	{
		if (hit.penetrationDepth > 0)
		{
			dynamic_resolution(player.transform.position, player.rgdb.velocity, player.rgdb.mass, karma.transform.position, karma.rgdb.velocity, karma.rgdb.mass, hit, 1);
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
		player.xp += 10;
	}
		if (karma.health <= 0)
		{
			
			player.xp += 20;
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
	if (health == 0)
	{
		sfw::drawString(text, "0", 920, 740, 20, 20);
	}
	if (health == 1)
	{
		sfw::drawString(text, "1", 920, 740, 20, 20);
	}
	if (health == 2)
	{
		sfw::drawString(text, "2", 920, 740, 20, 20);
	}
	if (health == 3)
	{
		sfw::drawString(text, "3", 920, 740, 20, 20);
	}
	if (health == 4)
	{
		sfw::drawString(text, "4", 920, 740, 20, 20);
	}
	if (health == 5)
	{
		sfw::drawString(text, "5", 920, 740, 20, 20);
	}
	if (health == 6)
	{
		sfw::drawString(text, "6", 920, 740, 20, 20);
	}
	if (health == 7)
	{
		sfw::drawString(text, "7", 920, 740, 20, 20);
	}
	if (health == 8)
	{
		sfw::drawString(text, "8", 920, 740, 20, 20);
	}
	if (health == 9)
	{
		sfw::drawString(text, "9", 920, 740, 20, 20);
	}
	if (health == 10)
	{
		sfw::drawString(text, "10", 920, 740, 20, 20);
	}
	if (health == 11)
	{
		sfw::drawString(text, "11", 920, 740, 20, 20);
	}
	if (health == 12)
	{
		sfw::drawString(text, "12", 920, 740, 20, 20);
	}
	if (health == 13)
	{
		sfw::drawString(text, "13", 920, 740, 20, 20);
	}
	if (health == 14)
	{
		sfw::drawString(text, "14", 920, 740, 20, 20);
	}
	if (health == 15)
	{
		sfw::drawString(text, "15", 920, 740, 20, 20);
	}
	if (health == 16)
	{
		sfw::drawString(text, "16", 920, 740, 20, 20);
	}
	if (health == 17)
	{
		sfw::drawString(text, "17", 920, 740, 20, 20);
	}
	if (health == 18)
	{
		sfw::drawString(text, "18", 920, 740, 20, 20);
	}
	if (health == 19)
	{
		sfw::drawString(text, "19", 920, 740, 20, 20);
	}
	if (health == 20)
	{
		sfw::drawString(text, "20", 920, 740, 20, 20);
	}
	if (transform.position.x <= 0)
	{
		transform.position.x = 999;
	}
	if (transform.position.x >= 1000)
	{
		transform.position.x = 0;
	}
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
	if (transform.position.x <= 0)
	{
		transform.position.x = 999;
	}
	if (transform.position.x >= 1000)
	{
		transform.position.x = 0;
	}
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
			transform.position = vec2{ 600,60 };
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

void Player::respawn()
{
	if (sfw::getKey('R'))
	{
		health = 20;
		level = 0;
		transform.position = vec2{ 450,50 };
	}
}



void Death::move(Player & player, Transform t)
{
	if (transform.position.x <= 0)
	{
		transform.position.x = 999;
	}
	if (transform.position.x >= 1000)
	{
		transform.position.x = 0;
	}
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
	if (transform.position.x <= 1)
	{
		transform.position.x = 998;
	}
	if (transform.position.x >= 999)
	{
		transform.position.x = 1;
	}
	float speedToUse = 100;
	MOVE_BEHAVIOUR mb = Wander;

	if (dist(player.transform.position, transform.position) < 200)
		mb = FollowPlayer;
	switch (mb)
	{
	case OffScreenLeft:
		rgdb.force = vec2{ 100,0 };
		break;

	case OffScreenRight:
		rgdb.force = vec2{ 100,0 };
		break;

	case FollowPlayer:
		if (player.transform.position.x  > transform.position.x)
			rgdb.force -= vec2{ 200,0 };

		else if (player.transform.position.x < transform.position.x)
			rgdb.force += vec2{ 200,0 };
		break;

	case Wander:
		if (transform.position.x > 999)
		{
			directrion = false;
		}
		if (transform.position.x < 1)
		{
			directrion = true;
		}
		if (directrion)
		{
			rgdb.force = vec2{ 100,0 };
		}
		if (!directrion)
		{
			//transform.position.x += 5;
			rgdb.force = vec2{ 100,0 };
		}

		break;

	default:
		break;
	}
}

void NPC::respawn()
{

	if (health <= 0)
	{
		time -= sfw::getDeltaTime();
		//std::cout << time << "\n";
		if (time <= 0)
		{
			health = 15;
			time = 10;
			transform.position.x = rand() % 1000 + 1;
			transform.position.y = 40;
		}
	}
}
