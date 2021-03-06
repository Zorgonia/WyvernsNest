#pragma once

#include "../engine/core.hpp"
#include "staticHubObject.hpp"

#define PLAYER_VEL 10
#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 5


class HubPlayer : public Entity
{
public:
	HubPlayer(const std::string &filePath);
	HubPlayer(const std::string &filePath, int x, int y, std::vector<StaticHubObject *> obj);
	~HubPlayer();

	// override entity functions
	void handleEvent(const SDL_Event& event) override;
	void update(int delta) override;
	void render() override;

	// getter for player position
	int getPosX();
	int getPosY();

	// Flag for player's position in the transition area
	bool isPlayerTransition();

private:
	// Helper function for player position
	void move(int xlim, int ylim);

	// The player sprite
	Sprite playerSprite;

	// Player position
	int xPos, yPos;

	// Player velocity
	int xVel, yVel;

	// List of static objects
	std::vector<StaticHubObject *> statObjList;

	// Player collision box
	SDL_Rect mCollision;
};
