local _T = {}
_G["Net"] = _T

_T.AllCoroutine = {}
_T.CoroutineIndex = 0

function _T.Receive(key, fd, str)
	print("net Receive",key, fd, str)

	local co = _T.AllCoroutine[key]
	coroutine.resume(co, str)
end

function _T.Send(str)
	_T.CoroutineIndex = _T.CoroutineIndex + 1
	Client.Send(_T.CoroutineIndex, -1, str)

	local str = coroutine.yield()
	return str
	
	_T.AllCoroutine[_T.CoroutineIndex] = co

	coroutine.resume(co)

end

return _T