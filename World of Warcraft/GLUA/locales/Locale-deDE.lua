local L = LibStub("AceLocale-3.0"):NewLocale("GuildWelcome", "deDE")
if not L then return end

L["(.+) has joined the guild"] = "(.+) ist der Gilde beigetreten"
L["<Your message here>"] = "<Deine Nachricht>"
L["Message"] = "Nachricht"
L["Slash-Command"] = "GuildWelcome"
L["Slash-Command-Short"] = "gw"
L["The average amount of time (in seconds) between noticing a new member and your Welcome message"] = "Die durchschnittliche Zeitspanne (in Sekunden) zwischen dem Bemerken eines Neumitglieds und der Willkommensnachricht."
L["The message text to be displayed.  Note the string \"%s\" will be replaced with the username"] = "Der Nachrichtentext, der angezeigt werden soll. Der Platzhalter \"%s\" wird durch den Benutzernamen ersetzt."
L["Time"] = "Zeit"
L["Welcome %s"] = "Willkommen %s"
