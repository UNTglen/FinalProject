--[[ 
	File: simpleHello.lua
	Date: 11-3-2010
	Version: 1.0.0.0
	Notes: Program is designed to record an event and follow a given set of peramiters per given event. 
	
	TO DO: 
	--change register "PLAYER_LEVEL_UP" to register myself or someone else.
	--Record if a guild member levels and insert congratdulation message
	--Finish building guild greetings on logOn. 
]]--

--local L = LibStub("AceLocale-3.0"):GetLocale("GLUA");

simpleHello = {};
local event_happening = simpleHello;

function event_happening.OnLoad(self) -- Loads on player login --
	self:RegisterEvent("CHAT_MSG_SYSTEM");

	DEFAULT_CHAT_FRAME:AddMessage("[Scare Bears INC] Simple Hello Has Been Initiallized!");
	DEFAULT_CHAT_FRAME:AddMessage(" Ver. 1.0.0.11");
	DEFAULT_CHAT_FRAME:AddMessage(" Currently there are no /commands.");
end

function event_happening.OnEvent(self, event, ...)
	if ( (event =="CHAT_MSG_SYSTEM") then
	msg = arg1;
	name = arg2;
		if ( (msg == " has come online.") ) then
			if ( (name ~= self) ) then
				SendChatMessage("Hello "..name.."! Nice to see you on today!", "GUILD", nil, nil);
			end;
		end;
	end;
	
	end
end	



