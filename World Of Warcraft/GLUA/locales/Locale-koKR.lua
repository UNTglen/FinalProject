local L = LibStub("AceLocale-3.0"):NewLocale("GuildWelcome", "koKR")
if not L then return end

L["(.+) has joined the guild"] = "(.+) 님이 접속을 하였습니다."
L["<Your message here>"] = "<여기에 메세지를 입력 하세요!>"
L["Message"] = "메세지"
L["Slash-Command"] = "GuildWelcome"
L["Slash-Command-Short"] = "gw"
L["The average amount of time (in seconds) between noticing a new member and your Welcome message"] = "길드원이 접속하면 일반적인 시간(초 단위) 안에, 길드원에게 누구님 어서오세요 라는 메세지를 보냅니다."
L["The message text to be displayed.  Note the string \"%s\" will be replaced with the username"] = "메세지 글을 표시 합니다. 노트 칸에 \\\"%s\\\"은 사용자 이름을 변경하며 메세지를 보냅니다."
L["Time"] = "시간(초 단위)"
L["Welcome %s"] = "%s님 어서 오세요!"
