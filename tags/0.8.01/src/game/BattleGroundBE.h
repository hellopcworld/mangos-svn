/* 
 * Copyright (C) 2005,2006,2007 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __BATTLEGROUNDBE_H
#define __BATTLEGROUNDBE_H

class BattleGround;

enum BattleGroundBEObjectTypes
{
    BG_BE_OBJECT_DOOR_1      = 0,
    BG_BE_OBJECT_DOOR_2      = 1,
    BG_BE_OBJECT_DOOR_3      = 2,
    BG_BE_OBJECT_DOOR_4      = 3,
    BG_BE_OBJECT_BUFF_1      = 4,
    BG_BE_OBJECT_BUFF_2      = 5,
    BG_BE_OBJECT_MAX         = 6
};

class BattleGroundBEScore : public BattleGroundScore
{
    public:
        BattleGroundBEScore() {};
        virtual ~BattleGroundBEScore() {};
        //TODO fix me
};

class BattleGroundBE : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundBE();
        ~BattleGroundBE();
        void Update(time_t diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);

        void RemovePlayer(Player *plr, uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        bool SetupBattleGround();
        void HandleKillPlayer(Player* player, Player *killer);

    private:
        uint32 m_TeamKills[2];                              // count of kills for each team
};
#endif