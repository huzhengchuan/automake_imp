tb = {
	reboot_list = "",
	}


-- read table info from lua
function loadstate()
	fn = "upd_state_flow.lua"
	fi = io.open(fn , "r");
	if(nil == fi) then
		print("open fail failed");
	end
	str_info = fi:read("*a");

	str_info = "return  "  .. str_info;

	print(str_info);

	func = load(str_info);
	tb = func();
	if(nil == tb) then
		print("loadstring failed");	
	else
		print(tb.reboot_list);
	end

end

function print_debug()
	print(tb.reboot_list);
end

-- debug case
loadstate();
print_debug();




	-- serial the table into lua file 
function serialize(obj)
	local lua = ""
	local t = type(obj)
	if t == "number" then
		lua = lua .. obj
	elseif t == "boolean" then
		lua = lua .. tostring(obj)
	elseif t == "string" then
		lua = lua .. string.format("%q", obj)
	elseif t == "table" then
		lua = lua .. "{\n"
		for k, v in pairs(obj) do
			lua = lua .. "[" .. serialize(k) .. "]=" .. serialize(v) .. ",\n"
		end
		local metatable = getmetatable(obj)
		if metatable ~= nil and type(metatable.__index) == "table" then
			for k, v in pairs(metatable.__index) do
				lua = lua .. "[" .. serialize(k) .. "]=" .. serialize(v) .. ",\n"
			end
		end
		lua = lua .. "}"
	elseif t == "nil" then
		return nil
	else
		error("can not serialize a " .. t .. " type.")
	end
	return lua
end

--	local result = serialize(tb);
--	print("end");
--	print(result);
--	print("end");
