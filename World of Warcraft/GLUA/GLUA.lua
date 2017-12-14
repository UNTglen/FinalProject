--[[ 
	File: GLUA.lua
	Date: 11-3-2010
	Version: 1.0.1.1
	Notes: Program is designed to record an event and follow a given set of peramiters per given event. 
	
	TO DO: 
	--change register "PLAYER_LEVEL_UP" to register myself or someone else.
	--Record if a guild member levels and insert congratdulation message
	--Finish building guild greetings on logOn. 
]]--

--local L = LibStub("AceLocale-3.0"):GetLocale("GLUA");

GLUA = {};
local GuildLevelUp = GLUA;

function GuildLevelUp.OnLoad(self) -- Loads on player login --
	self:RegisterEvent("PLAYER_LEVEL_UP"); 
	--self:RegisterEvent("CHAT_MSG_SYSTEM");
	--[[self:RegisterEvent("CHAT_MSG_ACHIEVEMENT");
	self:RegisterEvent("CHAT_MSG_GUILD");
	self:RegisterEvent("CHAT_MSG_GUILD_ACHIEVEMENT");
	self:RegisterEvent("CHAT_MSG_PARTY");
	]]--
	DEFAULT_CHAT_FRAME:AddMessage("[Scare Bears INC] Guild Level Up Announcer has been initialized!");
	DEFAULT_CHAT_FRAME:AddMessage(" Ver. 1.0.0.11");
	DEFAULT_CHAT_FRAME:AddMessage(" Currently there are no /commands.");
end

function GuildLevelUp.OnEvent(self, event, ...)
	local race = UnitClass("player"); --local varable to record what race you are.
	--local name = string.match(msg, " has came online."); -- local varable to check who came online

	if ( (event == "PLAYER_LEVEL_UP") ) then --if a player levels up do the following
		for i=25000, 1, -1 do end;
		local lvl = UnitLevel("player"); --local varable to record what lvl you are.
		SendChatMessage("DING! Yeah thats right im now a level "..lvl.." "..race..".", "SAY", nil, nil);
	--[[elseif ( (event =="CHAT_MSG_SYSTEM") then
		if ( (name ~= self) ) then
			SendChatMessage("Hello "..name.."! Nice to see you on today!", "GUILD", nil, nil);
		end
	end]]--
	
	end
end	



