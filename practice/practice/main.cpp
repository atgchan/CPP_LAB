#include "stdafx.h"
#include <vector>
#include "Character.h"
#include "Player.h"
#include "NPC.h"
#include "Mob.h"

int main(void)
{
	std::vector<Character*> vChar;
	Player* player = new Player();
	NPC* npc = new NPC();
	Mob* mob = new Mob();

	vChar.push_back(player); 
	vChar.push_back(npc);
	vChar.push_back(mob);

	for (auto c : vChar)
	{
		c->Dead();
	}

	printf_s("CCharacter Size %d \n", sizeof(Character*));

	getchar();
}