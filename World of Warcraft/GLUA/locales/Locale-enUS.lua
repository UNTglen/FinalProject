local debug = false
--[===[@debug@
debug = true
--@end-debug@]===]

local L = LibStub("AceLocale-3.0"):NewLocale("GuildWelcome", "enUS", true, debug)

L["(.+) has joined the guild"] = true
L["<Your message here>"] = true
L["Message"] = true
L["Slash-Command"] = "GuildWelcome"
L["Slash-Command-Short"] = "gw"
L["The average amount of time (in seconds) between noticing a new member and your Welcome message"] = true
L["The message text to be displayed.  Note the string \"%s\" will be replaced with the username"] = true
L["Time"] = true
L["Welcome %s"] = true
