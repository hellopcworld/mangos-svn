DELETE FROM `spell_chain` WHERE `spell_id` IN (29801,30030,30033);

INSERT INTO `spell_chain` VALUES
(29801,0,29801,1),
(30030,29801,29801,2),
(30033,30030,29801,3);
