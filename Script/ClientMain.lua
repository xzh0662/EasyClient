print("Client main")


local Net = require "Net.Net"


co = coroutine.create(function ( ... )
		local str = coroutine.yield()
		print("!!!!!!!!!!", str)

		return str
	end)

local str = Net.Send("luaTest~~~~~~~~")
print("...........", str)
--Net.Send("luaTest1111~~~~~~~~")

--[[
function Receive(fd, str)
	print("Receive", fd, str)
end

print("Net.Receive", Net.Receive, Net)

_G["Receive"] = Net.Receive
]]
