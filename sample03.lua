function func1()
    print "call func1."
end

RegisterCallback("func1", func1)

a = 10
RegisterCallback("a", a)

function make_func2()
    local x = 0
    return function () x = x + 1; print("X="..x) end
end

RegisterCallback("func2", make_func2())
