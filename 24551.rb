n = gets.to_i
arr = []
i = 11
while i <= n
    arr.push(i)
    i = i *10+1
end

result = 0;
1.upto((1<<arr.size) - 1) do |i|
    bc = 0
    mul = 1
    arr.size.times do |j|
        if (i & (1<<j)) > 0
            mul = mul.lcm(arr[j])
            bc +=1
        end
    end
    if (bc & 1) == 1
        result += n /mul
    else
        result -= n /mul
    end
end
print result
