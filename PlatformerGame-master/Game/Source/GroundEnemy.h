#ifndef _GROUNDENEMY_H_
#define _GROUNDENEMY_H_

#include "Point.h"
#include "Entity.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class GroundEnemy : Entity
{
public:
	GroundEnemy(fPoint position, SDL_Texture* texture, Type type);
	
	bool Start();

	bool Update(float dt);

	bool Draw();

	void OnCollision(Collider* a, Collider* b);

private:
	Animation idleAnimation;
	Animation walkAnimRight;

	Animation* currentAnimation;

	Collider* collider;
	Collider* killEnemy;
};

#endif // _GROUNDENEMY_H_