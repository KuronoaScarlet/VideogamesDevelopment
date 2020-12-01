#include "GroundEnemy.h"
#include "App.h"
#include "Render.h"
#include "Player.h"
#include "Collisions.h"
#include "Collider.h"

GroundEnemy::GroundEnemy(fPoint position, SDL_Texture* texture, Type type) : Entity(position, texture, type)
{
	idleAnimation.loop = true;
	idleAnimation.PushBack({ 1, 1, 10, 12 });

	walkAnimRight.PushBack({ 13,0, 10, 13 });
	walkAnimRight.PushBack({ 25,0, 10, 13 });
	walkAnimRight.PushBack({ 37,1, 10, 12 });
	walkAnimRight.loop = true;
	walkAnimRight.speed = 0.1f;

	currentAnimation = &idleAnimation;

	SDL_Rect colE = { position.x, position.y, 10, 8 };
	collider = app->collisions->AddCollider(colE, Collider::Type::ENEMY);
}

bool GroundEnemy::Start()
{
	

	return true;
}

bool GroundEnemy::Update(float dt)
{
	position.x = position.x + 0.2f;
	currentAnimation = &walkAnimRight;
	currentAnimation->Update();
	collider->SetPos(position.x, position.y);

	return true;
}

bool GroundEnemy::Draw()
{
	SDL_Rect rectEnemy;
	rectEnemy = currentAnimation->GetCurrentFrame();
	app->render->DrawTexture(texture, position.x, position.y, &rectEnemy);

	return true;
}

void GroundEnemy::OnCollision(Collider* a, Collider* b)
{
	if (b == collider)
	{
		if (b->type == Collider::Type::LEFT_WALL)
		{
			position.x -= 1;
		}
		if (b->type == Collider::Type::RIGHT_WALL)
		{
			position.x += 1;
		}
	}
}