/* 
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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
#ifndef __BATTLEGROUNDNA_H
#define __BATTLEGROUNDNA_H

class BattleGround;

enum BattleGroundNAObjectTypes
{
    BG_NA_OBJECT_DOOR_1         = 0,
    BG_NA_OBJECT_DOOR_2         = 1,
    BG_NA_OBJECT_DOOR_3         = 2,
    BG_NA_OBJECT_DOOR_4         = 3,
    BG_NA_OBJECT_MAX            = 4
};

enum BattleGroundNAObjects
{
    BG_NA_OBJECT_TYPE_DOOR_1    = 183978,
    BG_NA_OBJECT_TYPE_DOOR_2    = 183980,
    BG_NA_OBJECT_TYPE_DOOR_3    = 183977,
    BG_NA_OBJECT_TYPE_DOOR_4    = 183979
};

class BattleGroundNAScore : public BattleGroundScore
{
    public:
        BattleGroundNAScore() {};
        virtual ~BattleGroundNAScore() {};
        //TODO fix me
};

class BattleGroundNA : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundNA();
        ~BattleGroundNA();
        void Update(time_t diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);

        void RemovePlayer(Player *plr, uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        bool SetupBattleGround();
        virtual void ResetBGSubclass();
        void HandleKillPlayer(Player* player, Player *killer);

    private:
        uint32 m_TeamKills[2];                              // count of kills for each team
};
#endif
