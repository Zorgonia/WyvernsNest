#pragma once

#include "../engine/core.hpp"
#include "hubPlayer.hpp"
#include "util/button.hpp"
#include "menus/pausemenu.hpp"
#include "util/cursor.hpp"
#include "staticHubObject.hpp"
#include "customization.hpp"

#include <vector>

#include <nlohmann/json.hpp>


class Hub : public State
{
public:
	Hub();
	~Hub();

	// State functions unchanged
	void handleEvent(const SDL_Event& e) override;
	void update(int delta) override;
	void render() override;

	// getter for static objects
	std::vector<StaticHubObject *> getStaticObjects();

private:
	// last level flag
	bool last_level = false;

	// hub state counter
	std::string hub_state = "1";

	// Init Sprites
	void initSprites(const std::string& filePath);

	// Init static objects
	void initStaticObjects(const std::string & filePath);

	// Combat state transition
	void switchToCombatState();

	// Backdrop
	Sprite backdrop;

	// The hub player
	HubPlayer player;

	// Pause state
	PauseMenu pauseMenu;

	// Mouse cursor
	Cursor cursor;

	// List of static objects
	std::vector<StaticHubObject *> statObjlist;

	// Warning box sprite
	Sprite warningContinueSprite;
	Sprite warningShopSprite;
	Sprite warningCustomSprite;
};
