#ifndef _ENTITYMANAGER_H_
#define _ENTITYMANAGER_H_

#include "Module.h"
#include "List.h"
#include "Point.h"
#include "Entity.h"

class EntityManager : public Module
{
public:
	EntityManager();

	// Destructor
	virtual ~EntityManager()
	{}

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void AddEntity(fPoint position, Entity::Type type);

	void DeleteEntity();

private:
	List<Entity*> entityList;

	SDL_Texture* gEnemyTexture;
	SDL_Texture* heartsTexture;
	SDL_Texture* coinsTexture;

	Entity* gEnemy;
	Entity* heart;
	Entity* coin;
};

#endif // _ENTITYMANAGER_H_